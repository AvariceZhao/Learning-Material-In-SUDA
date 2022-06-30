count=0
for i in range(1,15):
    for j in range (1,67):
        for k in range(1,101):
            if 15*i+3*j+2*k==200:
                count+=1
print(count)