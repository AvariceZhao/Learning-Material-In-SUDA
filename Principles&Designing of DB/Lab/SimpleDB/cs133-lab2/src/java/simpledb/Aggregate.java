package simpledb;

import java.util.*;

/**
 * The Aggregation operator that computes an aggregate (e.g., sum, avg, max,
 * min). Note that we only support aggregates over a single column, grouped by a
 * single column.
 */

    //Aggregate是较复杂的一个部分，聚合分为分组聚合和不分组聚合，聚合数据由多种类型，这里是整型和字符串两种
    //这里字符串的聚合操作相对简单，只有COUNT一种，对于整数由较多操作:MIN,MAX,SUM,AVG,COUNT
    //在聚合过程中需要给出对元组的哪一列进行聚合、是否分组、若分组还需要指定以哪一列的数据进行分组
    //对于不同聚合的数据类型实现也不同，因此需要分IntegerAggregator和StringAggregator
    //由于合并需要返回一个最终合并结果，通过阅读代码发现最终结果是每添加一个元组对答案结果进行更新，因此对于不同的聚合操作(MIN,MAX,SUM,CNT,AVG)需要不同的更新答案的方法
public class Aggregate extends Operator {

    //对于一个聚合操作，首先需要一张表：由元组迭代器给出，需要给出对哪一列聚合，对哪一列分组，聚合的操作类，聚合的一列的数据类型(用于区分StringAggregator和IntAggregator)
    private static final long serialVersionUID = 1L;
    private DbIterator tupleIterator;
    private final Integer aggFieldIndex;
    private final Integer groupByFieldIndex;
    private final Aggregator.Op Operation;
    private TupleDesc td;
    private DbIterator result=null;
    private final Type gbType;
    /**
     * Constructor.
     * 
     * Implementation hint: depending on the type of afield, you will want to
     * construct an {@link IntegerAggregator} or {@link StringAggregator} to help
     * you with your implementation of fetchNext().
     * 
     * 
     * @param child
     *            The DbIterator that is feeding us tuples.
     * @param afield
     *            The column over which we are computing an aggregate.
     * @param gfield
     *            The column over which we are grouping the result, or -1 if
     *            there is no grouping
     * @param aop
     *            The aggregation operator to use
     */

    //给出聚合所需的信息：所有需要聚合的元组，聚合列的下标，分组列的下标，分组操作
    //由于需要返回最终结果，因此在这里提前处理出结果的TupleDesc，最后只需要用td构造结果元组并填入数据即可
    public Aggregate(DbIterator child, int afield, int gfield, Aggregator.Op aop) {
        this.tupleIterator=child;
        this.aggFieldIndex=afield;
        this.groupByFieldIndex=gfield;
        this.Operation=aop;

        if(groupByFieldIndex==Aggregator.NO_GROUPING)
        {
            gbType=null;
            Type[] fieldTypes=new Type[]{Type.INT_TYPE};

            td= new TupleDesc(fieldTypes);
        }
        else
        {
            gbType=tupleIterator.getTupleDesc().getFieldType(groupByFieldIndex);
          Type[] fieldTypes=new Type[]{gbType,tupleIterator.getTupleDesc().getFieldType(aggFieldIndex)};

            td= new TupleDesc(fieldTypes);
        }
    }

    /**
     * @return If this aggregate is accompanied by a groupby, return the groupby
     *         field index in the <b>INPUT</b> tuples. If not, return
     *         {@link simpledb.Aggregator#NO_GROUPING}
     * */
    //返回分组列
    public int groupField() {
	if (groupByFieldIndex== Aggregator.NO_GROUPING)return Aggregator.NO_GROUPING;
    else return groupByFieldIndex;
    }

    /**
     * @return If this aggregate is accompanied by a group by, return the name
     *         of the groupby field in the <b>OUTPUT</b> tuples If not, return
     *         null;
     * */
    //返回分组列的名称
    public String groupFieldName() {
        if (groupByFieldIndex== Aggregator.NO_GROUPING)
	        return null;
        else
        {
            return tupleIterator.getTupleDesc().getFieldName(groupByFieldIndex);
        }
    }

    /**
     * @return the aggregate field
     * */
    //返回聚合列
    public int aggregateField() {
      return aggFieldIndex;
    }

    /**
     * @return return the name of the aggregate field in the <b>OUTPUT</b>
     *         tuples
     * */
    //返回聚合列的名称
    public String aggregateFieldName() {
        return tupleIterator.getTupleDesc().getFieldName(aggFieldIndex);
    }

    /**
     * @return return the aggregate operator
     * */
    //返回聚合操作
    public Aggregator.Op aggregateOp() {
    return Operation;
    }
    //返回聚合操作的名称
    public static String nameOfAggregatorOp(Aggregator.Op aop) {
	return aop.toString();
    }

    //打开元组迭代器
    public void open() throws NoSuchElementException, DbException,
	    TransactionAbortedException {
        super.open();
	    tupleIterator.open();
    }

    /**
     * Returns the next tuple. If there is a group by field, then the first
     * field is the field by which we are grouping, and the second field is the
     * result of computing the aggregate, If there is no group by field, then
     * the result tuple should contain one field representing the result of the
     * aggregate. Should return null if there are no more tuples.
     *
     * Hint: think about how many tuples you have to process from the child operator
     * before this method can return its first tuple.
     * Hint: notice that you each Aggregator class has an iterator() method
     */
    //fetchNext是获取聚合结果中的下一个元组
    //首先如果还没有计算结果则需要首先遍历元组迭代器，不断调用Merge函数,计算所有元组的聚合结果，否则从结果的迭代器中不断取出下一个结果即可
    //根据聚合列的数据类型的不同，选择使用IntAggregate和StringAggregate
    protected Tuple fetchNext() throws TransactionAbortedException, DbException {
        if(result==null) {//如果结果还没有计算则先计算一遍结果
            if (this.tupleIterator.getTupleDesc().getFieldType(aggFieldIndex) == Type.INT_TYPE)
            {
                IntegerAggregator agg = new IntegerAggregator(groupByFieldIndex, gbType, aggFieldIndex, Operation);
                open();
                while (tupleIterator.hasNext()) agg.mergeTupleIntoGroup(tupleIterator.next());
                result=agg.iterator();
            }
            else
            {
                StringAggregator agg=new StringAggregator(groupByFieldIndex, gbType, aggFieldIndex, Operation);
                open();
                while (tupleIterator.hasNext()) agg.mergeTupleIntoGroup(tupleIterator.next());
                result=agg.iterator();
            }
            result.open();

        }
        if (result.hasNext())return result.next();//结果计算完后不断取出新的元组即可
        else return null;
    }

    //重置结果的迭代器
    public void rewind() throws DbException, TransactionAbortedException {
        if(result!=null)
            result.rewind();

    }

    /**
     * Returns the TupleDesc of this Aggregate. If there is no group by field,
     * this will have one field - the aggregate column. If there is a group by
     * field, the first field will be the group by field, and the second will be
     * the aggregate value column.
     * 
     * The name of an aggregate column should be informative. For example:
     * "aggName(aop) (child_td.getFieldName(afield))" where aop and afield are
     * given in the constructor, and child_td is the TupleDesc of the child
     * iterator.
     */
    //返回结果的元组描述
    public TupleDesc getTupleDesc() {
        return td;
    }

    //关闭迭代器
    public void close() {
	super.close();
    tupleIterator.close();
    }

    /**
     * See Operator.java for additional notes
     */
    @Override
    public DbIterator[] getChildren() {
    return new DbIterator[]{this.tupleIterator};
    }

    /**
     * See Operator.java for additional notes
     */
    @Override
    public void setChildren(DbIterator[] children) {
	this.tupleIterator=children[0];
    }
    
}
