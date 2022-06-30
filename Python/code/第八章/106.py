import re
s='''<composer>Wolfgang Amadeus Mozart</composer> 
<author>Samuel Beckett</author> 
<city>London</city>'''
res=re.findall(r'^<(\w+)>(.*)<',s,flags=re.M)
for i in res:
    print("{}:{}\n".format(i[0],i[1]),end="")