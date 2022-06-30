import time
days=time.time()//(3600*24)
hours=(time.time()-days*3600*24)/3600
print(days)
print(hours)