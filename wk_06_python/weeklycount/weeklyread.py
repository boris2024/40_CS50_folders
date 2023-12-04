import csv

inputfile=csv.reader(open("/workspaces/100391870/wk_06_python/weeklycount/helga231004.csv","r"))

count=0

for row in inputfile:
    print (row[24])

    if row[24]=="Venezuela" and row[8]=="ANULADO":
        count+=1

print(count)