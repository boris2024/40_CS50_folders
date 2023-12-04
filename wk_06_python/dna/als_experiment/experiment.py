
# 20230719

import csv
import sys

from sys import argv



# TODO: Check for command-line usage

if len(argv)!=2:
        print("Usage: python dna.py data.csv sample.txt")
        sys.exit(1)

else:
        candidates_file=sys.argv[1]

    # list with candidates data, with their STR counts
candidates_csv=[]

    # list with sample data, this is the actual DNA sample
sequence=[]

    # TODO: Read database file into a variable

with open(candidates_file,'r') as file:
    csv_reader=csv.reader(file)

    for row in csv_reader:
        candidates_csv.append(row)

with open(candidates_file,"r") as f:
    sequence=f.read()

print()
print("this is using csv.reader(filename)")
print(candidates_csv)
print()
print("this is using .read()")
print(sequence)

x=candidates_csv[0]
print(candidates_csv[0])

x[0]

print(x[0])