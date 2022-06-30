#输入成绩求平均值的改写程序1

numbers = []
flag = ""
while flag != "n":
    x = input("请输入一个成绩：")
    numbers.append(float(x))
    flag = ""
    while flag not in ["y", "n"]:
        flag = input("继续输入吗？（y/n）")
        flag = flag[0].lower()
        if flag not in ["y", "n"]:
            print("只能输入y或n")

print("平均成绩 = %.2f" % (sum(numbers) / len(numbers)))
