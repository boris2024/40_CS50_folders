
from cs50 import get_int

while True:

    n=get_int("What is the height of the pyramid? ")

    if n>0: break

for i in range(n):
    print("*")