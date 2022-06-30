#函数之间相互调用的安全保护（有隐患）

import math

def triangle(a, b, c):
    p = (a + b + c) / 2
    s = math.sqrt(p * (p-a) * (p-b) * (p-c))
    return s


if __name__=="__main__":
    x, y, z = 3, 4, 8
    print(triangle(x, y, z))

