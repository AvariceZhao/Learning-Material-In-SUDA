#今天是今年第几天的改写程序1

import time

date = time.localtime()                          #获取当前日期时间
year, month, day = date[:3]
print(year, month, day)

day_month = [[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
             [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]]

if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0):   #判断是否为闰年
    flag = 1
else:
    flag = 0

print(sum(day_month[flag][:month-1]) + day)
