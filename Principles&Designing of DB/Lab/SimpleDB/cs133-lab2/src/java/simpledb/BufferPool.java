package simpledb;

//import sun.text.resources.ext.JavaTimeSupplementary_hi_IN;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * BufferPool manages the reading and writing of pages into memory from
 * disk. Access methods call into it to retrieve pages, and it fetches
 * pages from the appropriate location.
 * <p>
 * The BufferPool is also responsible for locking;  when a transaction fetches
 * a page, BufferPool checks that the transaction has the appropriate
 * locks to read/write the page.
 * 
 * @Threadsafe, all fields are final
 */
public class BufferPool {
    //缓冲池用于将page从磁盘上加载到内存中，取数据时如果数据所在page在缓冲池中则可以直接取，提高效率。
    /** Bytes per page, including header. */
    public static final int PAGE_SIZE = 4096;

    private static int pageSize = PAGE_SIZE;

    /** Default number of pages passed to the constructor. This is used by
    other classes. BufferPool should use the numPages argument to the
    constructor instead. */
    public static final int DEFAULT_PAGES = 50;

    /** TODO for Lab 4: create instance of Lock Manager class. 
	Be sure to instantiate it in the constructor. */

    /**
     * Creates a BufferPool that caches up to numPages pages.
     *
     * @param numPages maximum number of pages in this buffer pool.
     */
    private final Map<PageId,Page>pageCache;//定义map用作缓冲池的功能，每个page与唯一的pageid相对应，用作map的键，page和pageid都是接口类型，实现在heappage和heappageid中
    private final int PageMaxNum;//缓冲池中所能存储的最大页面数
    public BufferPool(int numPages) {
        // some code goes here
        this.PageMaxNum=numPages;
        this.pageCache=new HashMap<>();
    }
    
    public static int getPageSize() {
      return pageSize;
    }//获取页面文件大小

    /**
     * Helper: this should be used for testing only!!!
     */
    public static void setPageSize(int pageSize) {
	BufferPool.pageSize = pageSize;
    }//设置页面文件大小
    /**
     * Helper: this should be used for testing only!!!
     */
    public static void resetPageSize(int pageSize) {
	BufferPool.pageSize = PAGE_SIZE;
    }//重置页面文件大小

    /**
     * Retrieve the specified page with the associated permissions.
     * Will acquire a lock and may block if that lock is held by another
     * transaction.
     * <p>
     * The retrieved page should be looked up in the buffer pool.  If it
     * is present, it should be returned.  If it is not present, it should
     * be added to the buffer pool and returned.  If there is insufficient
     * space in the buffer pool, a page should be evicted and the new page
     * should be added in its place.
     *
     * @param tid the ID of the transaction requesting the page
     * @param pid the ID of the requested page
     * @param perm the requested permissions on the page
     */
    public  Page getPage(TransactionId tid, PageId pid, Permissions perm)//获取页面
        throws TransactionAbortedException, DbException {
        // some code goes here
        //首先检索缓冲池中是否存在指定页面
        if(this.pageCache.containsKey(pid))return this.pageCache.get(pid);

        //没有找到则需要根据pid寻找该页面
        DbFile table=Database.getCatalog().getDatabaseFile(pid.getTableId());
        Page newPage=table.readPage(pid);
        this.addNewPage(pid,newPage);
        return newPage;
        //return null;
    }

    /**
     * Add new page to the buffer pool.
     * If there is insufficient space in the buffer pool,
     * a page should be evicted and the new page should be added in its place.
     *
     * @param pid the ID of the page to be added
     * @param newPage the page of the page to be added
     */

    private void addNewPage(PageId pid,Page newPage)throws DbException//向缓存池中加入新页面
    {
        if(this.pageCache.size()<this.PageMaxNum)//如果容量足够则直接加入
            this.pageCache.put(pid,newPage);
        else
            throw new DbException("缓冲池空间不足");//抛出异常
    }
    /**
     * Releases the lock on a page.
     * Calling this is very risky, and may result in wrong behavior. Think hard
     * about who needs to call this and why, and why they can run the risk of
     * calling it.
     *
     * @param tid the ID of the transaction requesting the unlock
     * @param pid the ID of the page to unlock
     */
    public  void releasePage(TransactionId tid, PageId pid) {
        // some code goes here
        // not necessary for lab1|lab2

	//lockmgr.releaseLock(tid,pid); // Uncomment for Lab 4
    }

    /**
     * Release all locks associated with a given transaction.
     *
     * @param tid the ID of the transaction requesting the unlock
     */
    public void transactionComplete(TransactionId tid) throws IOException {
        transactionComplete(tid,true);
    }

    /** Return true if the specified transaction has a lock on the specified page */
    public boolean holdsLock(TransactionId tid, PageId p) {
        // some code goes here
        // not necessary for lab1|lab2

	//return lockmgr.holdsLock(tid, p); // Uncomment for Lab 4 (remove "return false");
        return false;
    }

    /**
     * Commit or abort a given transaction; release all locks associated to
     * the transaction.
     *
     * @param tid the ID of the transaction requesting the unlock
     * @param commit a flag indicating whether we should commit or abort
     */
    public void transactionComplete(TransactionId tid, boolean commit)
        throws IOException {
        // some code goes here
        // not necessary for lab1|lab2

	// After dealing with commit/abort actions, ask lock manager to release locks
	//lockmgr.releaseAllLocks(tid); // Uncomment for Lab 4

    }

    /**
     * Add a tuple to the specified table on behalf of transaction tid.  Will
     * acquire a write lock on the page the tuple is added to and any other 
     * pages that are updated (Lock acquisition is not needed for lab2). 
     * May block if the lock(s) cannot be acquired.
     * 
     * Marks any pages that were dirtied by the operation as dirty by calling
     * their markDirty bit, and adds versions of any pages that have 
     * been dirtied to the cache (replacing any existing versions of those pages) so
     * that future requests see up-to-date pages. 
     *
     * @param tid the transaction adding the tuple
     * @param tableId the table to add the tuple to
     * @param t the tuple to add
     */
    public void insertTuple(TransactionId tid, int tableId, Tuple t)
        throws DbException, IOException, TransactionAbortedException {
        // some code goes here
        // not necessary for lab1
    }

    /**
     * Remove the specified tuple from the buffer pool.
     * Will acquire a write lock on the page the tuple is removed from and any
     * other pages that are updated. May block if the lock(s) cannot be acquired.
     *
     * Marks any pages that were dirtied by the operation as dirty by calling
     * their markDirty bit, and adds versions of any pages that have 
     * been dirtied to the cache (replacing any existing versions of those pages) so
     * that future requests see up-to-date pages. 
     *
     * @param tid the transaction deleting the tuple.
     * @param t the tuple to delete
     */
    public void deleteTuple(TransactionId tid, Tuple t)
        throws DbException, IOException, TransactionAbortedException {
        // some code goes here
        // not necessary for lab1
    }

    /**
     * Flush all dirty pages to disk.
     * Be careful using this routine -- it writes dirty data to disk so will
     *     break simpledb if running in NO STEAL mode.
     */
    public synchronized void flushAllPages() throws IOException {
        // some code goes here
        // not necessary for lab1

    }

    /** Remove the specific page id from the buffer pool.
        Needed by the recovery manager to ensure that the
        buffer pool doesn't keep a rolled back page in its
        cache.
    */
    public synchronized void discardPage(PageId pid) {
        // some code goes here
        // not necessary for labs 1--4
    }

    /**
     * Flushes (i.e., writes) a certain page to disk by asking 
     * the correct HeapFile to write the page
     * @param pid an ID indicating the page to flush
     */
    private synchronized void flushPage(PageId pid) throws IOException {
        // some code goes here
        // not necessary for lab1
    }

    /** Write all pages of the specified transaction to disk.
     */
    public synchronized void flushPages(TransactionId tid) throws IOException {
        // some code goes here
        // not necessary for labs 1--4
    }

    /**
     * Discards a page from the buffer pool.
     * Flushes the page to disk to ensure dirty pages are updated on disk.
     */
    private synchronized void evictPage() throws DbException {
        // some code goes here
        // not necessary for lab1
    }

}
