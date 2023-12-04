
#20230704

inventory=[]

# use this loop to add 3 books, title and author

for i in range(2):

    book=dict()
    book["title"]=input("what is the book's name?: ").lower()
    book["author"]=input("what is the name of the author?: ").upper()
    #print(book)

    inventory.append(book)

for book in inventory:
    print(book)