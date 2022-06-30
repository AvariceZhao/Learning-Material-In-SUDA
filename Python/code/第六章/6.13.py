l=[['000','name1'],['001',"name0"],['002','name2'],['003','name3']]
l.sort(key=lambda x:x[1])
for i in l:
    print("{} {}\n".format(i[0],i[1]))
l.sort(key=lambda x:x[0])
print("_"*100)
for i in l:
    print("{} {}\n".format(i[1],i[0]))

