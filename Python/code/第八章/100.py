import re
url=input("input a URL")
r=re.match(r'^([a-zA-Z]+):\/\/([a-zA-Z0-9.]+)(?:|:(\d+))\/(.*?)(?:|\?(.*))$',url)
t=r.groups()
print("协议:{}\n主机域名或IP:{}\n端口:{}\n路径:{}\n参数:{}\n".format(t[0],t[1],t[2],t[3],t[4]))