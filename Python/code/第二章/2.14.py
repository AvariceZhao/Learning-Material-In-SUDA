money=0
for i in range(5):
    money=(money+100)*1.005
print("%.5f"%money)
ans=(money-500)/5
print("%.2f%%"%ans)
