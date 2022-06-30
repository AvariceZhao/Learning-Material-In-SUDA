#输入成绩求平均值的改写程序2

numbers = []
while True:
    x = float(input("请输入一个成绩："))
    if x < 0:
        break
    numbers.append(float(x))

print("平均成绩 = %.2f" % (sum(numbers) / len(numbers)))
