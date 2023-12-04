
# 20231003

# example from geeks for geeks, dates comparison in py
# https://www.geeksforgeeks.org/comparing-dates-python/

import datetime
from datetime import date


# enter the dates for comparison in format yyyy/mm/dd

date01=datetime.date(2022,5,4)

date02=datetime.date(2024,9,23)

datecurrent = date.today()

if date01<datecurrent:
    print("true!!")

if date01<datecurrent and datecurrent<date02:
    print("this is also true!!")