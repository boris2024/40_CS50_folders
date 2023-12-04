
# 20230708

# example of function wrapper
# https://www.geeksforgeeks.org/function-wrappers-in-python/

#'''

# defining the decorator
def hello_decorator(func):
    # inner1 is a wrapper fxn in which the argument is called

    # inner function can access the outer local functions, in this case the function called "func"

    def inner1():
        print("FIRST, hello, this is before function execution")

        # calling the actual function now inside the thr wrapper function
        func()

        print("THIRD, this is after function execution")

    return inner1


# defining a function, to be called inside wrapper
def function_to_be_used():
    print("SECOND, This is inside the function !!")

# passing 'function_to_be_used' inside the decorator to control its behavior
function_to_be_used = hello_decorator(function_to_be_used)

# calling the function
function_to_be_used()