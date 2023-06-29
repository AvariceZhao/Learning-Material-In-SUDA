package simpledb;

import java.io.Serializable;

/**
 * Predicate compares tuples to a specified Field value.
 */
    //Predicate为Filter提供判断单个元组是否符合特定条件的功能
    //判断元组的某个field是否符合某一个条件即A OP B需要元组指定元组的field作为A，比较符OP，以及operand作为B
public class Predicate implements Serializable {

    private static final long serialVersionUID = 1L;

    private int field;
    private Op op;
    private Field operand;
    /** Constants used for return codes in Field.compare */
    public enum Op implements Serializable {
        EQUALS, GREATER_THAN, LESS_THAN, LESS_THAN_OR_EQ, GREATER_THAN_OR_EQ, LIKE, NOT_EQUALS;

        /**
         * Interface to access operations by integer value for command-line
         * convenience.
         * 
         * @param i
         *            a valid integer Op index
         */
        public static Op getOp(int i) {
            return values()[i];
        }

        public String toString() {
            if (this == EQUALS)
                return "=";
            if (this == GREATER_THAN)
                return ">";
            if (this == LESS_THAN)
                return "<";
            if (this == LESS_THAN_OR_EQ)
                return "<=";
            if (this == GREATER_THAN_OR_EQ)
                return ">=";
            if (this == LIKE)
                return "LIKE";
            if (this == NOT_EQUALS)
                return "<>";
            throw new IllegalStateException("impossible to reach here");
        }

    }
    
    /**
     * Constructor. Creates a Predicate that can be used to filter tuples by
     * comparing one of the tuples' fields to the given operand using the given op.
     * 
     * @param field
     *            field number of passed in tuples to compare against.
     * @param op
     *            operation to use for comparison
     * @param operand
     *            field value to compare passed in tuples to
     */
    //构造函数，即给出A OP B，如num <= 5
    public Predicate(int field, Op op, Field operand) {
        this.field=field;
        this.op=op;
        this.operand=operand;
    }

    /**
     * @return the field number
     */
    //返回元组的field的下标
    public int getField()
    {
        return this.field;
    }

    /**
     * @return the operator
     */
    //返回比较符
    public Op getOp()
    {
        return this.op;
    }
    
    /**
     * @return the operand
     */
    //返回比较数
    public Field getOperand()
    {
        return this.operand;
    }
    
    /**
     * Compares the field number of t specified in the constructor to the
     * operand field specified in the constructor using the operator specific in
     * the constructor. The comparison can be made through Field's compare
     * method.
     * 
     * @param t
     *            The tuple to compare against
     * @return true if the comparison is true, false otherwise.
     */
    //判断这个元组的指定field是否符合条件
    public boolean filter(Tuple t) {
        return t.getField(field) .compare(op,operand);
    }

    /**
     * Returns something useful, like "f = field_id op = op_string operand =
     * operand_string"
     */
    //以字符串形式返回这个比较操作的信息
    public String toString() {
        String ans;
        ans = "f= "+Integer.toString(field)+" op = "+op.toString()+" operand = "+operand.toString();
        return ans;
    }
}
