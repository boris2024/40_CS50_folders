
# 20230710, 20230711

menu={
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}


total=0
counter=0

while True:

    try:
        entree=input("item: ").title()

    # linear search for entree in dictionary keys
        if entree not in menu:
            continue

        else:
            total=total+menu[entree]

            new_total="${:.2f}".format(total)
            print(new_total)

            counter+=1

            #if counter==5:
                #break

    # note that the only way to stop the program is through the exception, otherwise it will keep prompting the user for an item
    except EOFError:
        print()
        break


#print()