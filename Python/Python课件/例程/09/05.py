#警察与小偷

for i in range(32):
    lst = ['0'] * 5
    lst.extend(bin(i)[2:])
    lst = lst[-5:]
    a = int(lst[0])
    b = int(lst[1])
    c = int(lst[2])
    d = int(lst[3])
    e = int(lst[4])

    r = 0
    r += b and c            #a说
    r += not b              #b说
    r += (a or b)           #c说
    r += not a and not d    #d说
    r += not e              #e说
    if r == 4:
        print(lst)