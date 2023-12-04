
import csv

file=open("phonebook04.csv","a")

while True:
    name= input("enter name: ")
    dob= input("enter dob (format yyyymmdd): ")

    anynamevar=csv.writer(file)
    anynamevar.writerow([name,dob])

    print()
    question=input("add more people to db? write yes/no: ")

    if question=="no":
        break
        print("file ready, check you csv file")

file.close()
