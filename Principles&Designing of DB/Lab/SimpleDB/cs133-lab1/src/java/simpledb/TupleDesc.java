package simpledb;

import java.io.Serializable;
import java.util.*;

/**
 * TupleDesc describes the schema of a tuple.
 */
//TupleDesc用于描述Tuple的一行
public class TupleDesc implements Serializable {

    private ArrayList<TDItem> tdAr;//特定类型的字段列表
    //创建TDItem类型的ArrayList用于描述一行Tuple的信息，TDItem类有fieldType和fieldname两个成员变量，用于描述Tuple的单个单位的类型，名称
    //如fileName=“年龄”,fieldType=Int
    //采用Array便于返回迭代器遍历容器
    public static class TDItem implements Serializable {

        private static final long serialVersionUID = 1L;

        public final Type fieldType;//字段类型

        public final String fieldName;//字段名称

        public TDItem(Type t, String n) {//构造字段
            this.fieldName = n;
            this.fieldType = t;
        }

        public String toString() {
            return fieldName + "(" + fieldType + ")";
        }
    }


    public Iterator<TDItem> iterator() {//返回字段列表的迭代器
        // some code goes here
        return tdAr.iterator();//用arraylist可以直接返回迭代器
    }

    private static final long serialVersionUID = 1L;


    //构造函数，给出类型和名称的动态数组，构造TupleDesc
    public TupleDesc(Type[] typeAr, String[] fieldAr) {

        this.tdAr=new ArrayList<TDItem>();
        //判断参数合法性
        if(typeAr.length==0||fieldAr.length==0)throw new IllegalArgumentException("数组至少包含一个元素");
        if(typeAr.length!=fieldAr.length)throw new IllegalArgumentException("类型数组和名称数组长度必须一致");
        //构造字段
        for(int i=0;i<typeAr.length;i++)
        {
            tdAr.add(new TDItem(typeAr[i],fieldAr[i]));
        }
    }


    //只给出类型的动态数组，构造TupleDesc
    public TupleDesc(Type[] typeAr) {
        //可以调用前面的构造函数进行构造
        this(typeAr,new String [typeAr.length]);

    }


    //返回列表的元素个数
    public int numFields() {
        return tdAr.size();
    }


    //获取TupleDesc数组的第i个的名称
    public String getFieldName(int i) throws NoSuchElementException {
        if(i<0||i>=tdAr.size())throw  new NoSuchElementException();//判断参数合法性
        return tdAr.get(i).fieldName;//返回字段名称
    }


    //获取TupleDesc数组的第i个的类型
    public Type getFieldType(int i) throws NoSuchElementException {
        if(i<0||i>=tdAr.size())throw  new NoSuchElementException();//判断参数合法性
        return tdAr.get(i).fieldType;//返回字段类型
    }


    //根据名称寻找下标
    public int fieldNameToIndex(String name) throws NoSuchElementException {

        int pos=-1;
        for(int i=0;i<tdAr.size();i++)
                if(Objects.equals(name, tdAr.get(i).fieldName))
                {
                    pos=i;
                    break;
                }
        if(pos==-1)throw new NoSuchElementException("字段'" + name + "'未找到");//未找到则抛出异常
        return pos;
    }


    //计算TupleDesc字节大小
    public int getSizeInBytes() {
        int total=0;
        //计算总字节大小需要遍历tdAr，单个字节大小由Type类型的fieldType决定，通过阅读Type.java了解到可以通过getSizeInBytes函数获得字节大小，getSizeInBytes的实现通过枚举类型返回不同值
        for (TDItem tdItem : tdAr) total += tdItem.fieldType.getSizeInBytes();//遍历字段列表并累加
        return total;
    }


    //合并两个TupleDesc，合并的总长度为两个的长度相加。由于前面的构造函数采用数组为参数，故这里开辟新数组存储，最后调用构造函数返回即可
    public static TupleDesc merge(TupleDesc td1, TupleDesc td2) {
         int len1=td1.numFields(),len2=td2.numFields();//获取两个字段数组长度
         Type[] tempType=new Type[len1+len2];//创建合并后的字段类型以及名称数组
         String[] tempString=new String[len1+len2];
         //合并操作
        //先填td1
         for(int i=0;i<len1;i++)
         {
             tempType[i]= td1.getFieldType(i);
             tempString[i]=td1.getFieldName(i);
         }
         //再填td2
         for(int i=0;i<len2;i++)
         {
             tempType[len1+i]=td2.getFieldType(i);
             tempString[len1+i]=td2.getFieldName(i);
         }
         return new TupleDesc(tempType,tempString);//返回结果
    }


    //判断相等
    public boolean equals(Object o) {
        if(this==o)return true;//如果是自身则直接返回
        if(o instanceof  TupleDesc)//如果是实例则继续比较
        {
            TupleDesc other=(TupleDesc)o;
            if(this.tdAr.size()!=other.tdAr.size())
                return false;
            for(int i=0;i<tdAr.size();i++)
            {
                if(!this.getFieldType(i).equals(other.getFieldType(i)))
                        return false;
            }
            return true;
        }
        return false;

    }

    public int hashCode() {
        // If you want to use TupleDesc as keys for HashMap, implement this so
        // that equal objects have equals hashCode() results
        throw new UnsupportedOperationException("unimplemented");
    }


    public String toString() {
        // some code goes here
        StringBuilder ans= new StringBuilder("TupleDesc:");
        for(int i=0;i<this.tdAr.size();i++)
        {
            ans.append(this.tdAr.get(i).toString());
            if(this.tdAr.size()-1!=i)
                    ans.append(",");
        }
        return ans.toString();
    }
}
