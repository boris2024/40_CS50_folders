import sys

names=["miranda","celeste","diego","andrea","tete","roro"]

word=input("what is the name? ")

if word in names:
    print("found!!")
    sys.exit(0)

print("not found!!")
sys.exit(1)


