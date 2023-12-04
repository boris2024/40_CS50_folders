
# 20230704 example of how to read data from a csv file using python code

import csv

familydob=[]

# read csv with family information

with open("phonebook04.csv") as file:
    text=file.read()
    print(text)