with open('cat1.txt','r') as f1:
    content=f1.read()
with open('cat2.txt','a+') as f2:
    f2.write(content)
