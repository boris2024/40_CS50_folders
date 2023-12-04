
# 20231003

#import datetime

from datetime import date, timedelta

current = date.today()

date_plus_xdays=current+timedelta(days=6)
date_minus_xdays=current-timedelta(days=6)

print ("")

print ("current date is:",current)
print ("")

print("date 6 days from today=",date_plus_xdays)
print("date 6 days before today=",date_minus_xdays)

print ("")