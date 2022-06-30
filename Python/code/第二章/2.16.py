from datetime import datetime
time1=input("")
time2=input("")
time1=datetime.strptime(time1,"%H:%M:%S")
time2=datetime.strptime(time2,"%H:%M:%S")
print((time2-time1).seconds)
