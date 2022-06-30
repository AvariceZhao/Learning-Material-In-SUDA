#函数之间相互调用的安全保护（更安全）

import math

def triangle(a, b, c):
    if a >= b + c or b >= a + c or c >= a + b:
        return None
    p = (a + b + c) / 2
    s = math.sqrt(p * (p-a) * (p-b) * (p-c))
    return s


if __name__=="__main__":
    x, y, z = 3, 4, 7
    if x < y + z and y < x + z and z < x + y:
        print(triangle(x, y, z))
    else:
        print("ERROR")
    #print(triangle(x, y, z))
