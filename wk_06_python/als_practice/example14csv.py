
# 20230704 example of how to read data from a csv file using python code, using fxns from csv module

import csv

familydob=[]

# read csv with family information

print()

with open("phonebook02.csv") as file:
    file_reader=csv.DictReader(file)

    #book is just a variable name, nothing special

    for book in file_reader:
        print(book)
        # this is what we use to append to our initial list called familydob
        familydob.append(book)
print()

print(familydob)
print()
