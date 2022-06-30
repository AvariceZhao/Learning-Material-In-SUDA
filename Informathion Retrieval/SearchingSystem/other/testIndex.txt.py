import base64
f=open('image.jpg','rb') #二进制方式打开图文
file=open('image.txt','w+',encoding='utf8')
ls_f=base64.b64encode(f.read()) #读取文件内容，转换为base64编码
f.close()
file.write(str(ls_f))
file.close()