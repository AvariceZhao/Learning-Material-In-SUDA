#用字典做索引实现键表的快速查询

import timeit
import random

def gen_key_list(n):
    if n < 1:
        return set()
    lst1 = {x for x in range(1, n)}
    lst2 = {random.randint(1, n - 1) for i in range(n // 2)}
    lst2 -= {998}
    lst2.add(999)
    lst1 -= lst2
    return list(lst1)

def gen_index(lst):
    idx = dict()
    for i in range(len(lst)):
        idx[lst[i]] = i
    return idx

def search1(lst, key):
    for i in range(len(lst)):
        if lst[i] == key:
            return i
    return -1

def search2(lst, key, idx):
    return idx.get(key, -1)

def search3(lst, key):
    return lst.index(key)


if __name__ == '__main__':
    t = timeit.default_timer()
    keylist = gen_key_list(1000000)

    print("生成键表时间：%.9f" % (timeit.default_timer() - t))
    print("生成键表长度：%d" % (len(keylist)))

    t = timeit.default_timer()
    keyindex = gen_index(keylist)
    print("建立索引时间：%.9f" % (timeit.default_timer() - t))

    # 任意找
    t = timeit.default_timer()
    p = search1(keylist, 998)
    print("位置：%4d, 查询时间：%.9f(search1)" % (p, timeit.default_timer() - t))
    
    t = timeit.default_timer()
    p = search2(keylist, 998, keyindex)
    print("位置：%4d, 查询时间：%.9f(search2)" % (p, timeit.default_timer() - t))

    # 找不到
    t = timeit.default_timer()
    p = search1(keylist, 999)
    print("位置：%4d, 查询时间：%.9f(search1)" % (p, timeit.default_timer() - t))

    t = timeit.default_timer()
    p = search2(keylist, 999, keyindex)
    print("位置：%4d, 查询时间：%.9f(search2)" % (p, timeit.default_timer() - t))

'''
    t = timeit.default_timer()
    p = search3(keylist, 999)
    print("位置：%4d, 查询时间：%.9f" % (p, timeit.default_timer() - t))
'''
