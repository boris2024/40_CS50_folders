
# 20230708

# defining a decorator

def hello_decorator(func):

    def inner1():
        print("hello, this is before fxn execution")
        func()
        print("this is after fxn execution")

    return inner1

def function_to_be_used():
    print("this is inside the fxn !")

function_to_be_used=hello_decorator(function_to_be_used)

function_to_be_used()



