f1 = open("out_ans.txt",'r',encoding="utf-8-sig")
f2 = open('Answer.txt','r',encoding="utf-8-sig")

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


print('Precision={}/{}={:.2f}%'.format(cnt,sumAns,P*100))
print('Recall={}/{}={:.2f}%'.format(cnt,sumStd,R*100))
print('F值=({}/{})*({}/{})*2/({}/{}+{}/{})={:.2f}%'.format(cnt,sumAns,cnt,sumStd,cnt,sumAns,cnt,sumStd,F*100))
