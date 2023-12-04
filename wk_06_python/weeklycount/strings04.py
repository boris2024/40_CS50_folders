
# 20231004

# convert string to datetime
# https://www.geeksforgeeks.org/python-convert-string-to-datetime-and-vice-versa/

# Python String to Datetime using Datetime.Strptime()

import datetime

def convert(date_time):
    format='%Y-%m-%d'
    datetime_str=datetime.datetime.strptime(date_time, format)

    return datetime_str

test='2026-04-12'

print(convert(test))
