#输入成绩求平均值的原始程序
numbers = []
while True:
    x = input("请输入一个成绩：")
    numbers.append(float(x))
    while True:
        flag = input("继续输入吗？（y/n）")
        if flag.lower() not in ["y", "n"]:
            print("只能输入y或n")
        else:
            break
    if flag.lower() == "n":
        break

print("平均成绩 = %.2f" % (sum(numbers) / len(numbers)))
