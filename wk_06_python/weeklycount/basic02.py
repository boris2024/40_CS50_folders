
# 20231003

from datetime import timedelta, datetime

current_date_time=datetime.now()

print("")
print("current date and time:", current_date_time)

# date, 6 days from today

date_plus_6days=current_date_time+timedelta(days=6)
date_minus_6days=current_date_time-timedelta(days=6)

print("")
print("date 6 days from today=",date_plus_6days)
print("date 6 days before today=",date_minus_6days)
print("")
