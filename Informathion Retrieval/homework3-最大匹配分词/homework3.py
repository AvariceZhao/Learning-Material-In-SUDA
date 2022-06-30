def WordMatch():
    f = open("Dict.txt", 'r', encoding='utf8')
    words = []
    for i in f.readlines():
        words.append(i.replace("\n", ""))

    words.pop(0)
    maxlen = 0
    for i in words:
        maxlen = max(maxlen, len(i))

    f = open("Sentence.txt", 'r', encoding='utf8')
    sentences = f.readlines()
    f.close()
    f = open("out_ans.txt", 'w+', encoding='utf-8')
    for i in sentences:
        back = 0
        counts = 0
        l = len(i)
        while counts < l:
            for j in range(maxlen, 0, -1):  # 枚举切片长度
                if i[back:back + j] in words:  # 判断是否匹配，匹配则打印
                    # print(i[back:back+j],end=" ")
                    f.write(i[back:back + j] + " ")
                    back += j  # 将当前位置指针右移
                    counts += j
                    break
                if j == 1:
                    # print(i[back],end=" ")
                    f.write(i[back] + " ")
                    back += 1
                    counts += 1
                    break
    f.close()
def Assess():
    f1 = open("out_ans.txt", 'r', encoding="utf-8-sig")
    f2 = open('Answer.txt', 'r', encoding="utf-8-sig")

    ans = f1.readline().split()
    std = f2.readline().split()
    sumAns = 0
    sumStd = 0
    cnt = 0

    while ans:
        i = 0
        j = 0
        la = len(ans[0])
        ls = len(std[0])

        while i < len(ans) and j < len(std):
            if ans[i] == std[j]:
                cnt += 1
                i += 1
                j += 1
                if i < len(ans):
                    la += len(ans[i])
                if j < len(std):
                    ls += len(std[j])
            elif ls > la and i < len(ans):
                i += 1
                if i < len(ans):
                    la += len(ans[i])
            elif j < len(std):
                j += 1
                if j < len(std):
                    ls += len(std[j])
        sumAns += len(ans)
        sumStd += len(std)

        ans = f1.readline().split()
        std = f2.readline().split()

    P = cnt / sumAns
    R = cnt / sumStd
    F = P * R * 2 / (P + R)

    print('Precision={}/{}={:.2f}%'.format(cnt, sumAns, P * 100))
    print('Recall={}/{}={:.2f}%'.format(cnt, sumStd, R * 100))
    print('F值=({}/{})*({}/{})*2/({}/{}+{}/{})={:.2f}%'.format(cnt, sumAns, cnt, sumStd, cnt, sumAns, cnt, sumStd,
                                                              F * 100))


WordMatch()
print("Word match Completed!")
# Assess()



