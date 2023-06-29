package simpledb;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Computes some aggregate over a set of StringFields.
 */
//StringAggregator用于实现String类型的聚合操作，只有CNT一种操作类型
public class StringAggregator implements Aggregator {


    private static final long serialVersionUID = 1L;
    private final int  gbfield;
    private final Type gbfieldtype;
    private final int aggfield;
    private final Op AggOperation;
    HashMap<Field,Integer>result;
    /**
     * Aggregate constructor
     * @param gbfield the 0-based index of the group-by field in the tuple, or NO_GROUPING if there is no grouping
     * @param gbfieldtype the type of the group by field (e.g., Type.INT_TYPE), or null if there is no grouping
     * @param afield the 0-based index of the aggregate field in the tuple
     * @param what aggregation operator to use -- only supports COUNT
     * @throws IllegalArgumentException if what != COUNT
     */
    //构造函数，给出聚合操作所需的必要信息，分组列，分组类型，聚合列，聚合操作
    public StringAggregator(int gbfield, Type gbfieldtype, int afield, Op what) {
       this.gbfield=gbfield;
       this.gbfieldtype=gbfieldtype;
       this.aggfield=afield;
       this.AggOperation=what;
       result=new HashMap<>();
    }

    /**
     * Merge a new tuple into the aggregate, grouping as indicated in the constructor
     * @param tup the Tuple containing an aggregate field and a group-by field
     */
    //因为String的聚合操作在这里只有CNT一种，所以不需要分操作类型，直接合并结果即可
    public void mergeTupleIntoGroup(Tuple tup) {
      StringField aggField=(StringField) tup.getField(aggfield);
      Field gbField;
      if(gbfield==NO_GROUPING)gbField=null;
      else gbField=tup.getField(gbfield);

      if(result.containsKey(gbField))
      result.put(gbField,result.get(gbField)+1);
      else
          result.put(gbField,1);
    }

    /**
     * Returns a DbIterator over group aggregate results.
     *
     * @return a DbIterator whose tuples are the pair (groupVal,
     *   aggregateVal) if using group, or a single (aggregateVal) if no
     *   grouping. The aggregateVal is determined by the type of
     *   aggregate specified in the constructor.
     */
    //返回结果的迭代器，根据是否分组构造不同的TupleDesc，随后遍历result填入数据即可
    public DbIterator iterator() {
        Type[] fieldTypes;
        String[] fieldNames;
        TupleDesc tupleDesc;
        List<Tuple> tuples = new ArrayList<>();
        if(gbfield==NO_GROUPING)
        {
            fieldTypes = new Type[]{Type.INT_TYPE};
            fieldNames = new String[]{"aggregateValue"};
            tupleDesc = new TupleDesc(fieldTypes,fieldNames);
            Tuple tuple = new Tuple(tupleDesc);
            IntField resultField = new IntField(result.get(gbfield));
            tuple.setField(0,resultField);
            tuples.add(tuple);
        }
        else
        {
            fieldTypes=new Type[]{gbfieldtype,Type.INT_TYPE};
            fieldNames=new String[]{"group","aggregateVal"};
            tupleDesc=new TupleDesc(fieldTypes,fieldNames);
            for(Field field: result.keySet())
            {
                Tuple tuple=new Tuple(tupleDesc);
                if(gbfieldtype==Type.INT_TYPE)
                {
                    IntField resultField =  (IntField)field;
                    tuple.setField(0,resultField);
                }
                else
                {
                    StringField resultField=(StringField) field;
                    tuple.setField(0,resultField);
                }
                IntField ansField=new IntField(result.get(field));
                tuple.setField(1,ansField);
                tuples.add(tuple);
            }
        }
        return new TupleIterator(tupleDesc,tuples);

    }

}
