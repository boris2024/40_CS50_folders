import datetime
import csv


inputfile=csv.reader(open("/workspaces/100391870/wk_06_python/weeklycount/00sample33.csv","r"))

start_date=datetime.date(2023,9,4)

end_date=datetime.date(2023,9,30)

delta=datetime.timedelta(days=6)

count=0
count2=0

print(start_date)

print(start_date,end="\n")

while (start_date<=end_date):
    #print(start_date, end="\n")
    start_date+= delta
    print(start_date,end="\n")
    #count+=1
    #print(count, end="\n")

    for row in inputfile:
        #print (row[24])
        if row[1]>=start_date and row[1]<=end_date+delta:
            count2+=1

    print(count2)