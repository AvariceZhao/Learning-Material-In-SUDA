import datetime
datetime1=datetime.datetime.now()
datetime2=datetime1+datetime.timedelta(hours=1.25)
print(datetime2.strftime("%H:%M:%S"))
