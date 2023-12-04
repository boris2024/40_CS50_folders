import csv
import sys

from sys import argv


def main():

    # TODO: Check for command-line usage

    if len(argv)!=3:
        print("Usage: python dna.py data.csv sample.txt")
        sys.exit(1)

    else:
        candidates_file=sys.argv[1]
        sample_file=sys.argv[2]

    # list with candidates data, with their STR counts
    candidates_csv=[]

    # list with header data from candidates file
    csv_header=[]

    # list with sample data, this is the actual DNA sample
    sequence=[]

    # TODO: Read database file into a variable

    with open(candidates_file,'r') as file:
        csv_reader=csv.DictReader(file)

        # used this to read header directly into a list
        csv_header=csv_reader.fieldnames

        for row in csv_reader:
            candidates_csv.append(row)


    x=len(csv_header)
    size=len(candidates_csv)

    # csv_header0 = list with all STR ids
    # csv_header0 does not contain the "name" as first word, it only coontains the names of candidates
    csv_header0=csv_header[1:x+1]

    str_quantity=len(csv_header0)

    # in this step the count for every STR is transformed from str to int,
    # in every row of the candidates_csv list
    for i in range(size):
        for j in range(str_quantity):
            candidates_csv[i][csv_header0[j]]=int(candidates_csv[i][csv_header0[j]])


    # TODO: Read DNA sequence file into a variable

    with open(sample_file,"r") as f:
        sequence=f.read()

    #print(f"sequence: {sequence}")

    # TODO: Find longest match of each STR in DNA sequence

    # this list holds the results for matches of particular STR's in each sample
    sample_results={}

    # here, add data to the dictionary
    for word in csv_header0:
        sample_results[word]=longest_match(sequence, word)

    #print(f"sample_results: {sample_results}")

    # TODO: Check database for matching profiles

    # adapt your algorithm to work with the large or small database, id based on the number of str
    # keep it simple, be flexible



    # use this to naviate and scan data in a 2D list with dictionaries nested inside
    for candidate in candidates_csv:
        # must be located here at start of every row
        counter4=0
        for str in csv_header0:
            if (candidate[str]==sample_results[str]):
                counter4+=1

        # if all match
        if (counter4==str_quantity):
            print(candidate["name"])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found


    return longest_run


main()
