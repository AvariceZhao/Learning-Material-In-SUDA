from math import log10

n = int(input('请输入魔方阵的阶数：'))
assert n % 2 == 1 and n > 0

matrix = [[0]*n for _ in range(n)]

i, j = 0, n//2
for num in range(1, n*n+1):
    if matrix[i][j] == 0:
        matrix[i][j] = num
    else:
        i = (i+2) % n
        j = (j-1) % n
        matrix[i][j] = num
    i = (i-1) % n
    j = (j+1) % n

digits = int(2*log10(n))+1
for row in matrix:
    print(*(str(num).rjust(digits, ' ') for num in row))
