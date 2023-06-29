package simpledb;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

/**
 * The Catalog keeps track of all available tables in the database and their
 * associated schemas.
 * For now, this is a stub catalog that must be populated with tables by a
 * user program before it can be used -- eventually, this should be converted
 * to a catalog that reads a catalog table from disk.
 * 
 * @Threadsafe
 */
public class Catalog {

    //catalog管理数据库中的表，故需要记录表名，表的主键，表在磁盘上的文件，文件对应的ID，即对于一张表需要存储以上的信息
    //可以采用四元组存储，但查找信息时效率太低，为了加速，这里采用Map进行存储
    //定义四种map，分别为ID-文件，ID-表名，表名-ID，ID-主键
    private final Map<Integer,DbFile>idFileMap;
    private final Map<Integer,String>idNameMap;
    private final Map<String,Integer>nameIdMap;
    private final Map<Integer,String>idPkeyMap;
    /**
     * Constructor.
     * Creates a new, empty catalog.
     */
    public Catalog() {//构造函数，初始化四个map
        this.idFileMap=new HashMap<>();
        this.idNameMap=new HashMap<>();
        this.nameIdMap=new HashMap<>();
        this.idPkeyMap=new HashMap<>();
    }

    /**
     * Add a new table to the catalog.
     * This table's contents are stored in the specified DbFile.
     * @param file the contents of the table to add;  file.getId() is the identfier of
     *    this file/tupledesc param for the calls getTupleDesc and getFile
     * @param name the name of the table -- may be an empty string.  May not be null.  If a name
     * conflict exists, use the last table to be added as the table for a given name.
     * @param pkeyField the name of the primary key field
     */
    //添加新表，需要表文件，表名，主键
    public void addTable(DbFile file, String name, String pkeyField) {
        //任何一个参数为空都不合法
        if(file==null||name==null||pkeyField==null)
                throw new IllegalArgumentException("invalid argument.");

        if(this.nameIdMap.containsKey(name))//判断表名是否重复，根据文件中的英文注释，重复则丢弃原来的信息
        {

            int existId=this.nameIdMap.get(name);
            //首先根据表名获取id，id与其他三种信息由直接的映射，故根据从map里删除对应的记录即可
            this.idFileMap.remove(existId);
            this.idNameMap.remove(existId);
            this.idPkeyMap.remove(existId);
            //最后移除表名
            this.nameIdMap.remove(name);
        }
        //添加新信息
        int tableId=file.getId();
        this.idFileMap.put(tableId,file);
        this.idNameMap.put(tableId,name);
        this.nameIdMap.put(name,tableId);
        this.idPkeyMap.put(tableId,pkeyField);

    }

    //添加新表，不指定主键
    public void addTable(DbFile file, String name) {
        addTable(file, name, "");
    }

    /**
     * Add a new table to the catalog.
     * This table has tuples formatted using the specified TupleDesc and its
     * contents are stored in the specified DbFile.
     * @param file the contents of the table to add;  file.getId() is the identfier of
     *    this file/tupledesc param for the calls getTupleDesc and getFile
     */
    //不指定表名，则生成随机ID作为表名，与sqlsever中定义约束时没有指定约束名称则随机生成类似
    public void addTable(DbFile file) {
        addTable(file, (UUID.randomUUID()).toString());
    }

    /**
     * Return the id of the table with a specified name,
     * @throws NoSuchElementException if the table doesn't exist
     */
    //由表名获取表ID
    public int getTableId(String name) throws NoSuchElementException {

        if(name==null||!this.nameIdMap.containsKey(name))//判断参数合法性
        {
            throw  new NoSuchElementException("表名"+name+"未找到");
        }
        //返回表ID
        return this.nameIdMap.get(name);
    }

    /**
     * Returns the tuple descriptor (schema) of the specified table
     * @param tableid The id of the table, as specified by the DbFile.getId()
     *     function passed to addTable
     * @throws NoSuchElementException if the table doesn't exist
     */
    //由表id获取表的描述
    public TupleDesc getTupleDesc(int tableid) throws NoSuchElementException {
        // some code goes here
        if(!this.idFileMap.containsKey(tableid))//表不存在
                throw new NoSuchElementException("表id="+tableid+"未找到");

        return this.idFileMap.get(tableid).getTupleDesc();
        //return null;
    }

    /**
     * Returns the DbFile that can be used to read the contents of the
     * specified table.
     * @param tableid The id of the table, as specified by the DbFile.getId()
     *     function passed to addTable
     */
    //根据表id获取文件
    public DbFile getDatabaseFile(int tableid) throws NoSuchElementException {
        // some code goes here
        if (!this.idFileMap.containsKey(tableid))//如果表id不存在
            throw new NoSuchElementException("表id=" + tableid + "未找到");
        return this.idFileMap.get(tableid);
    }

    //根据表id获取主键
    public String getPrimaryKey(int tableid) {
        // some code goes here
        if(!this.idPkeyMap.containsKey(tableid))//如果表id不存在
            throw new NoSuchElementException("表id=" + tableid + "未找到");
        return this.idPkeyMap.get(tableid);
    }
    //获取表id的迭代器
    public Iterator<Integer> tableIdIterator() {
        // some code goes here
        return this.idNameMap.keySet().iterator();
    }

    //根据表id获取表名
    public String getTableName(int tableid) {
        // some code goes here
        if(!this.idNameMap.containsKey(tableid))
            throw new NoSuchElementException("表id=" + tableid + "未找到");
        return this.idNameMap.get(tableid);
    }
    
    /** Delete all tables from the catalog */
    //清除表目录
    public void clear() {
        // some code goes here
        this.idNameMap.clear();
        this.idPkeyMap.clear();
        this.idFileMap.clear();
        this.nameIdMap.clear();
    }
    
    /**
     * Reads the schema from a file and creates the appropriate tables in the database.
     * @param catalogFile
     */
    public void loadSchema(String catalogFile) {
        String line = "";
        String baseFolder=new File(new File(catalogFile).getAbsolutePath()).getParent();
        try {
            BufferedReader br = new BufferedReader(new FileReader(new File(catalogFile)));
            
            while ((line = br.readLine()) != null) {
                //assume line is of the format name (field type, field type, ...)
                String name = line.substring(0, line.indexOf("(")).trim();
                //System.out.println("TABLE NAME: " + name);
                String fields = line.substring(line.indexOf("(") + 1, line.indexOf(")")).trim();
                String[] els = fields.split(",");
                ArrayList<String> names = new ArrayList<String>();
                ArrayList<Type> types = new ArrayList<Type>();
                String primaryKey = "";
                for (String e : els) {
                    String[] els2 = e.trim().split(" ");
                    names.add(els2[0].trim());
                    if (els2[1].trim().toLowerCase().equals("int"))
                        types.add(Type.INT_TYPE);
                    else if (els2[1].trim().toLowerCase().equals("string"))
                        types.add(Type.STRING_TYPE);
                    else {
                        System.out.println("Unknown type " + els2[1]);
                        System.exit(0);
                    }
                    if (els2.length == 3) {
                        if (els2[2].trim().equals("pk"))
                            primaryKey = els2[0].trim();
                        else {
                            System.out.println("Unknown annotation " + els2[2]);
                            System.exit(0);
                        }
                    }
                }
                Type[] typeAr = types.toArray(new Type[0]);
                String[] namesAr = names.toArray(new String[0]);
                TupleDesc t = new TupleDesc(typeAr, namesAr);
                HeapFile tabHf = new HeapFile(new File(baseFolder+"/"+name + ".dat"), t);
                addTable(tabHf,name,primaryKey);
                System.out.println("Added table : " + name + " with schema " + t);
            }
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(0);
        } catch (IndexOutOfBoundsException e) {
            System.out.println ("Invalid catalog entry : " + line);
            System.exit(0);
        }
    }
}

