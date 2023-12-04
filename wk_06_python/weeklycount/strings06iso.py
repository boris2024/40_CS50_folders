
# 20231004

# construct a date from string in iso format

import datetime

date='2024-06-25'

# Calling fromisoformat() function to construct a datetime.date object

new_date=datetime.date.fromisoformat(date)

print("the date with new format is= ",new_date)