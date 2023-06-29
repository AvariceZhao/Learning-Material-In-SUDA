package simpledb;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Computes some aggregate over a set of IntFields.
 */


    //IntegerAggregator是聚合操作的重点部分，用于实现对Int类型的各种聚合操作
    //通过mergeTupleIntoGroup函数得知聚合操作计算结果的方法是不断将一个新元组合并到当前的答案中，如对于Max操作即ans=max(ans,tuple.num),
    //由于不同的聚合操作更新答案的方法都不同，所以对于每个操作定义一种类用于更新结果，根据构造函数中给出的操作类型的不同，定义不同的类，在更新答案时同理
    //MIN,SUM,MAX,CNT操作的更新都相对简单，只需要一个HashMAP即可，但对于AVG操作的处理相对麻烦，AVG=SUM/CNT，需要记录SUM,CNT，才能在加入新元组时不断更新结果
public class IntegerAggregator implements Aggregator {


    private static final long serialVersionUID = 1L;
    private final int gbfield;
    private final Type gbfieldtype;
    private final int aggfield;
    private final Op OP;
    //定义不同操作的更新
    private MinAgg minAgg;
    private AvgAgg avgAgg;
    private SumAgg sumAgg;
    private MaxAgg maxAgg;
    private CntAgg cntAgg;


    //构造函数，根据操作类型的不同，使用不同的类
    public IntegerAggregator(int gbfield, Type gbfieldtype, int afield, Op what) {
        this.gbfield = gbfield;
        this.gbfieldtype = gbfieldtype;
        this.aggfield = afield;
        this.OP=what;
        if (what == Op.MIN) minAgg = new MinAgg();
        else if (what == Op.AVG) avgAgg = new AvgAgg();
        else if (what == Op.SUM) sumAgg = new SumAgg();
        else if (what == Op.MAX) maxAgg = new MaxAgg();
        else cntAgg = new CntAgg();
    }

    /**
     * Merge a new tuple into the aggregate, grouping as indicated in the
     * constructor. See Aggregator.java for more.
     *
     * @param tup the Tuple containing an aggregate field and a group-by field
     */
    //向答案中合并一个新的元组
    public void mergeTupleIntoGroup(Tuple tup) {
        IntField aggField = (IntField) tup.getField(aggfield);
        Field gbField;
        if (gbfield == NO_GROUPING) gbField = null;
        else gbField = tup.getField(gbfield);

        if (OP == Op.MIN) minAgg.Add(gbField, aggField);
        else if (OP == Op.AVG) avgAgg.Add(gbField, aggField);
        else if (OP == Op.SUM) sumAgg.Add(gbField, aggField);
        else if (OP == Op.MAX) maxAgg.Add(gbField, aggField);
        else cntAgg.Add(gbField, aggField);;


    }

    /**
     * Returns a DbIterator over group aggregate results.
     *
     * @return a DbIterator whose tuples are the pair (groupVal, aggregateVal)
     * if using group, or a single (aggregateVal) if no grouping. The
     * aggregateVal is determined by the type of aggregate specified in
     * the constructor.
     */

    //返回结果的迭代器，首先需要根据操作类型的不同，从不同的类获取合并的结果
    public DbIterator iterator() {
        HashMap<Field, Integer> result;
        if (OP == Op.MIN)result = minAgg.getResult();
        else if (OP == Op.AVG) result = avgAgg.getResult();
        else if (OP == Op.SUM) result = sumAgg.getResult();
        else if (OP == Op.MAX)result = maxAgg.getResult();
        else result = cntAgg.getResult();

        Type[] fieldTypes;
        String[] fieldNames;
        TupleDesc tupleDesc;
        List<Tuple> tuples = new ArrayList<>();
        if (gbfield == NO_GROUPING) {
            //定义结果的TupleDesc
            fieldTypes = new Type[]{Type.INT_TYPE};
            fieldNames = new String[]{"aggregateValue"};
            tupleDesc = new TupleDesc(fieldTypes, fieldNames);
            //定义结果元组
            Tuple tuple = new Tuple(tupleDesc);
            IntField resultField = new IntField(result.get(null));
            //填入数据
            tuple.setField(0, resultField);
            tuples.add(tuple);
        } else {
            //定义结果的TupleDesc
            fieldTypes = new Type[]{gbfieldtype, Type.INT_TYPE};
            fieldNames = new String[]{"group", "aggregateVal"};
            tupleDesc = new TupleDesc(fieldTypes, fieldNames);

            for (Field field : result.keySet()) {
                //定义结果元组
                Tuple tuple = new Tuple(tupleDesc);
                if (gbfieldtype == Type.INT_TYPE) {
                    //填入数据
                    IntField resultField = (IntField) field;
                    tuple.setField(0, resultField);
                } else {
                    //填入数据
                    StringField resultField = (StringField) field;
                    tuple.setField(0, resultField);
                }
                //填入数据
                IntField ansField = new IntField(result.get(field));
                tuple.setField(1, ansField);
                //将结果添加到元组列表中
                tuples.add(tuple);
            }
        }
        //返回结果的调用TupleIterator类返回结果的元组迭代器
        return new TupleIterator(tupleDesc, tuples);
    }


    //定义处理Sum操作的类
    private class SumAgg {
        HashMap<Field, Integer> Result;

        public SumAgg() {
            Result = new HashMap<>();
        }

        public HashMap<Field, Integer> getResult() {
            return this.Result;
        }

        void Add(Field gbField, IntField aggField) {
            int val = aggField.getValue();
            if (Result.containsKey(gbField)) {
                Result.put(gbField, val + Result.get(gbField));
            } else {
                Result.put(gbField, val);
            }

        }
    }
    //定义处理Max操作的类
    private class MaxAgg {

        HashMap<Field, Integer> Result;

        public MaxAgg() {
            Result = new HashMap<>();
        }

        public HashMap<Field, Integer> getResult() {
            return this.Result;
        }

        void Add(Field gbField, IntField aggField) {
            int val = aggField.getValue();
            if (Result.containsKey(gbField)) {
                Result.put(gbField, Math.max(val, Result.get(gbField)));
            } else {
                Result.put(gbField, val);
            }
        }
    }

    //定义处理Min操作的类
    private class MinAgg {

        HashMap<Field, Integer> Result;

        public MinAgg() {
            Result = new HashMap<>();
        }

        public HashMap<Field, Integer> getResult() {
            return this.Result;
        }

        void Add(Field gbField, IntField aggField) {
            int val = aggField.getValue();
            if (Result.containsKey(gbField)) {
                Result.put(gbField, Math.min(val, Result.get(gbField)));
            } else {
                Result.put(gbField, val);
            }
        }
    }

    //定义处理AVG操作的类
    private class AvgAgg {
        HashMap<Field, Integer> Sum;
        HashMap<Field, Integer> Count;
        HashMap<Field, Integer> Result;

        public HashMap<Field, Integer> getResult() {
            return this.Result;
        }

        private AvgAgg() {
            Result = new HashMap<>();
            Sum = new HashMap<>();
            Count = new HashMap<>();
        }


        void Add(Field gbField, IntField aggField) {

            Integer val = aggField.getValue();

            if (Sum.containsKey(gbField) && Count.containsKey(gbField)) {


                Sum.put(gbField, Sum.get(gbField) + val);
                Count.put(gbField, Count.get(gbField) + 1);
            } else {
                Sum.put(gbField, val);
                Count.put(gbField, 1);
            }
            Integer avg = Sum.get(gbField) / Count.get(gbField);
            Result.put(gbField, avg);
        }
    };
    //定义处理CNT操作的类
    private class CntAgg {
        HashMap<Field, Integer> Result;

        public CntAgg() {
            Result = new HashMap<>();
        }

        public HashMap<Field, Integer> getResult() {
            return this.Result;
        }

        void Add(Field gbField, IntField aggField) {
            if (Result.containsKey(gbField)) {
                Result.put(gbField, Result.get(gbField) + 1);
            } else {
                Result.put(gbField, 1);
            }
        }
    };
}

