package simpledb;

import java.util.*;

/**
 * Filter is an operator that implements a relational select.
 */
public class Filter extends Operator {
    //Filter支持给定一些元组，过滤元组中符合特定要求的元组，对应与SQL中的WHERE子句
    //单个Filter由给定筛选条件p和一个元组迭代器child定义
    //由于记录中的筛选条件有多种，在数值上有>,=,<,>=,<=,==,<>等，字符串有LIKE等，为实现程序的模块化，因此将判断单个元组是否符合条件单独分成一个类Predicate，虽然实际使用的时候只有predicate的filter函数有用？
    //但这个Filter只支持单个条件查询，对于WHERE里有AND的只需把不断用新的条件筛选前一次的结果即可，对于OR条件只需将多个条件的筛选结果合并后去重即可
    private static final long serialVersionUID = 1L;
    private  Predicate p;
    private DbIterator child;
    /**
     * Constructor accepts a predicate to apply and a child operator to read
     * tuples to filter from.
     * 
     * @param p
     *            The predicate to filter tuples with
     * @param child
     *            The child operator
     */
    //构造函数，给出筛选条件和元组的迭代器
    public Filter(Predicate p, DbIterator child) {
        this.p=p;
        this.child=child;

    }

    //返回筛选条件
    public Predicate getPredicate() {
      return this.p;
    }

    //返回元组描述
    public TupleDesc getTupleDesc() {
        return this.child.getTupleDesc();
    }

    //打开迭代器，为使用迭代器遍历元组做准备
    public void open() throws DbException, NoSuchElementException,
            TransactionAbortedException {
        super.open();
        this.child.open();
    }

    //关闭迭代器，代表不再访问
    public void close() {
        super.close();
       this.child.close();
    }

    //将迭代器重新恢复到初始位置
    public void rewind() throws DbException, TransactionAbortedException {

        this.child.rewind();
    }

    /**
     * The Filter operator iterates through the tuples from its child, 
     * applying the predicate to them and returning those that
     * pass the predicate (i.e. for which the Predicate.filter() returns true.)
     * This method returns the next tuple.
     * 
     * @return The next tuple that passes the filter, or null if there are no
     *         more tuples
     * @see Predicate#filter
     */
    //从迭代器中获取下一个符合predicate条件的元组
    protected Tuple fetchNext() throws NoSuchElementException,
            TransactionAbortedException, DbException {

        while(child.hasNext())//如果没有访问结束就不断取下一个并判断是否符合条件，直到找到符合条件的元组或遍历结束为止
        {
            Tuple t=child.next();
            if(p.filter(t))
                return t;
        }
        return null;
    }
    
    /**
     * See Operator.java for additional notes 
     */
    @Override
    public DbIterator[] getChildren() {
        return new DbIterator[]{this.child};
    }
    
    /**
     * See Operator.java for additional notes 
     */
    @Override
    public void setChildren(DbIterator[] children) {
        this.child=children[0];
    }

}
