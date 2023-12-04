
#20231004

import datetime
#from datetime import date

input=['2023-04-12','2025-06-23','2020-09-14','2027-03-04']

format='%Y-%m-%d'

date01=datetime.date(2019,5,4)

date02=datetime.date(2026,9,23)



for i in input:
    dia=(datetime.datetime.strptime(i,format).date())
    print(dia)
    if date01<dia and dia<date02:
        print("it's within range")
    else:
        print("it is out of bounds")