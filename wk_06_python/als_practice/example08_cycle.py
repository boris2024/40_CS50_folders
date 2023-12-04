
# 20230702 example how to use loop to cycle through dictionary
# here we use the .items method to transform the dictionary into a list
arepas={
    "queso blanco":100,
    "queso amarillo":200,
    "reina pepeada":300,
    "sardina":400
}

for sabor, precio in arepas.items():
    print(f"sabor: {sabor}, precio: {precio}")
