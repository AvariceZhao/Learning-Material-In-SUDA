list1=[["name1",30],["name2",41],["name3",20]]
def agesort(user):
    return user[1]
list1.sort(key=agesort,reverse=True)
print("姓名：{}\n年龄：{}".format(list1[0][0],list1[0][1]))
