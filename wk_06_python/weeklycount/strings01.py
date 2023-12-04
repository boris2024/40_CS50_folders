
# 20231004

import datetime

input='2025/05/01'
format='%Y/%m/%d'

datetime=datetime.datetime.strptime(input,format)

print(datetime.date())