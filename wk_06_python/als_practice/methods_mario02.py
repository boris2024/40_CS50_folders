
from cs50 import get_int

def get_height():
    while True:
        try:
            n=int(input("enter value of n: "))
            if n>0: break
        except ValueError:
            print("not an integer");

    return n

def main():
    height=get_height()

    for i in range(height):
        print("#")

main()

