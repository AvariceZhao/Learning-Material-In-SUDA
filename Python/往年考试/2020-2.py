import math


# 给定一个正整数，求升序排列的因数列表
def func1(n):
    return [i for i in range(2, n) if n % i == 0]


# 求a,b升序排列的公因数列表
def func2(a, b):
    return [i for i in range(2, min(a, b) + 1) if (a % i == 0 and b % i == 0)]


# 求列表的中位数
def func3(lst):
    return sorted(lst)[int((len(lst) + 1) / 2 - 1)] if len(lst) % 2 == 1 else int(
        (sorted(lst)[int(len(lst) / 2)] + sorted(lst)[int(len(lst) / 2 - 1)]) / 2)


# 求列表中有几个值有重复值
def func4(lst):
    return len(set([i for i in lst if lst.count(i) > 1]))


# 给定正整数n，求[2, n)内的回文质数，输出降序列表
def func5(n):
    return sorted(
        [i for i in range(2, n) if (str(i) == str(i)[::-1] and 0 not in [i % j for j in range(2, int(i ** 0.5 + 1))])],
        reverse=True)


# 求一个集合中有多少个数可以表达为该集合中另外两个数的和
def func6(s):
    return len(set([list(s)[i] + list(s)[j] for i in range(len(s)) for j in range(i, len(s)) if i != j]) & s)


# 将字符串正中间的4个字符改成“****”
def func7(s):
    return '****' if len(s) > 10 or len(s) < 6 else s[:int((len(s) - 4) / 2):] + '****' + s[int((len(s) - 4) / 2) + 4::] if len(s) % 2 == 0 else s[:-1:][:int((len(s) - 4 - 1) / 2):] + '****' + s[:-1:][int((len(s) - 4 - 1) / 2) + 4::] + s[-1]


# 找出等差数列中缺失的值
def func8(lst):
    return int((sorted(lst)[0] + sorted(lst)[-1]) * (len(lst) + 1) / 2 - sum(lst))


if __name__ == '__main__':
    #   print(func2(12,18))
    #   print(func3([40, -1, 13, 79, 120]))
    #    print(func4([8, 6, 7, 10, -2, 101]))
    print(func5(200))
    print(func6({1, 1, 1, 2}))
    print(func7("867102131"))
    print(func8([2, 4, 6, 8, 12]))
    pass
