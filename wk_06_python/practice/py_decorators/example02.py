
# 20230708

# https://www.geeksforgeeks.org/decorators-in-python/

# in py functions are 1st class objects

# py program to illustrate that functions can be passed as arguments to other functions, see line 16

# this is how it works:
# In the above example, the greet function takes another function
# as a parameter (shout and whisper in this case).
# The function passed as an argument is then called inside the function greet.

def shout(text):
    return text.upper()

def whisper(text):
    return text.lower()

# here func becomes either shout or whisper
def greet(func):
    # store the fxn in a var called greeting
    greeting=func("..hello there..")
    print(greeting)


greet(shout)

greet(whisper)