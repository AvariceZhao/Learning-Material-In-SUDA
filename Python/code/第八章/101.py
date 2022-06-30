word=input("input a word")
if word[-1]=='y':
    print(word[:-1]+'ies')
elif word[-1]=='o'or word[-1]=='s' or word[-1]=='o'or word[-1]=='x' or word[-1]=='z':
    print(word[:-1]+'es')
elif word[-2]=='ch' or word[-2]=='sh':
    print(word[-2]+'es')
else:
    print(word+'s')