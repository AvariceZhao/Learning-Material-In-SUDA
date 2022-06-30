num=int(input("input a number between 0 and 100"))
if num>=0 and num<=100:
    if num%3==0:
        print("YES")
    else:
        print("NO")
else:
    print("YOU NUMBER IS ERROR")
