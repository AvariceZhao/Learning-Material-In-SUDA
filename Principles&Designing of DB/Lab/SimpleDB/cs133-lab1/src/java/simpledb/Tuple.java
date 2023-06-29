package simpledb;

import java.io.Serializable;
import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;
/**
 * Tuple maintains information about the contents of a tuple. Tuples have a
 * specified schema specified by a TupleDesc object and contain Field objects
 * with the data for  each field.
 */
//Tuple可以认为是数据库中一张表的一条记录，Field即为每个记录的方格
public class Tuple implements Serializable {

    private static final long serialVersionUID = 1L;
    private TupleDesc desc;//定义当前元组的元组描述，一行记录需要描述具体存储的是哪些数据，如年龄，学号，姓名，还需要存储每种数据的类型，故对于每个Tuple都需要一个TupleDesc
    private  Field[] fields;//记录Tuple中的具体数据，如18 1001 张三...
    private  RecordId id;//记录编号，与Tuple在磁盘上位置相关
    /**
     * Create a new tuple with the specified schema (type).
     *
     * @param td
     *            the schema of this tuple. It must be a valid TupleDesc
     *            instance with at least one field.
     */
    public Tuple(TupleDesc td) {//根据元组描述创建新元组
        this.desc=td;//存储描述信息
        this.fields=new Field[td.numFields()];//Tuple存储的数据与数据的描述数量相等，故开辟指定大小新数组
        this.id=null;//由于没有给出RecordedID，故先设为null

    }

    /**
     * @return The TupleDesc representing the schema of this tuple.
     */
    //获取当前元组的元组描述
    public TupleDesc getTupleDesc() {
        return this.desc;
    }

    /**
     * @return The RecordId representing the location of this tuple on disk.
     *         Should return RecordId that was set with setRecordId(). May be null.
     */
    //获取记录编号
    public RecordId getRecordId() {
        return this.id;
    }

    /**
     * Set the RecordId information for this tuple.
     *
     * @param rid
     *            the new RecordId for this tuple.
     */
    //设置记录编号
    public void setRecordId(RecordId rid) {
        // some code goes here
        this.id=rid;
    }

    /**
     * Change the value of the ith field of this tuple.
     *
     * @param i
     *            index of the field to change. It must be a valid index.
     * @param f
     *            new value for the field.
     */
    //填写元组的第i个字段的内容
    public void setField(int i, Field f) {
        // some code goes here
        if(i<0||i>=this.fields.length)//判断下标合法性
            throw new NoSuchElementException(i+"is not a valid index.");

        this.fields[i]=f;//填写指定内容

    }

    /**
     * @return the value of the ith field, or null if it has not been set.
     *
     * @param i
     *            field index to return. Must be a valid index.
     */
    //获取元组的第i个字段的内容
    public Field getField(int i) {
        // some code goes here
        if(i<0||i>=this.fields.length)//判断下标合法性
            throw new NoSuchElementException(i+"is not a valid index.");
        return fields[i];
    }

    /**
     * Returns the contents of this Tuple as a string. Note that to pass the
     * system tests, the format needs to be as follows:
     *
     * column1\tcolumn2\tcolumn3\t...\tcolumnN\n
     *
     * where \t is any whitespace, except newline, and \n is a newline
     */
    public String toString() {//获取当前元组的内容

        StringBuilder str=new StringBuilder();//采用StringBuild实现字符串拼接，提高效率
        //遍历并进行字符串拼接
        for(int i=0;i<this.fields.length;i++)
        {
            str.append(fields[i]).append((this.fields.length-1==i)?'\n':'\t');
        }
        return str.toString();
    }
    
    /**
     * @return
     *        An iterator which iterates over all the fields of this tuple
     * */
    public Iterator<Field> fields()
    {
        return Arrays.stream(this.fields).iterator();
    }

    /**
     * Reset the TupleDesc of this tuple
     * (Only affecting the TupleDesc, does not need to worry about fields inside the Tuple)
     * */
    public void resetTupleDesc(TupleDesc td)
    {
        this.desc=td;
    }
}
