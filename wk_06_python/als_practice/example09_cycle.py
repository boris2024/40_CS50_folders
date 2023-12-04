
#20230702  another example of using the .items method to transform a dictionary into a list

# 1. create dictionary
print()

pizzas={
    "queso mozz":100,
    "jamon":230,
    "pepperoni":300,
    "pine apple":430
}

for sabor, precio in pizzas.items():
    print("a {} pizza costs: {} usd ".format(sabor,precio))

print()