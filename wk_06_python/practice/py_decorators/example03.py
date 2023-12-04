
# 20230708

# functions can return another function

# source: https://www.geeksforgeeks.org/decorators-in-python/

def create_adder(x):
    def adder(y):
        return x+y

    return adder

add_15=create_adder(15)

print(add_15(10))

'''
this is a comment !!
'''