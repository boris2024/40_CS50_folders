# 20230712

# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000



    # Ensure correct usage
if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # TODO: Read teams into memory from file
teams = []

filename=sys.argv[1]

with open(filename) as file:
    file_reader=csv.DictReader(file)

    # algo is just a variable name
    for algo in file_reader:

        teams.append(algo)

#print(teams)

# iterate over teams[]

for algo in range(len(teams)):
    teams[algo]['rating']=int((teams[algo]['rating']))


file.close()

print(teams)
