#蒙特霍问题
import random

max = 1000

c = 0
for i in range(max):
    doors = [0, 0, 1]
    random.shuffle(doors)
    choice = random.randint(0, 2)
    c += doors[choice]
print("不改选择的获胜概率 = %.3f" % (c / max))

c = 0
for i in range(max):
    doors = [0, 0, 1]
    random.shuffle(doors)
    choice = random.randint(0, 2)
    result = [0, 1, 2]
    result.remove(choice)
    choice = result[1] if doors[result[0]] == 0 else result[0]
    c += doors[choice]
print("改变选择的获胜概率 = %.3f" % (c / max))
