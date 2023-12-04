
# 20230707

class Student():

    def __init__(self, name, id):
        self.name=name
        self.id=id

    def changeID(self,id):
        id=int(input("What is the student's new id number?"))
        self.id=id

    def print(self):
        #print("{} - {}".format(self.name,self.id))
        print()
        print(f"name = {self.name}, id no. = {self.id}")
        print()

name=input("What is the student's name ? ")

id=int(input("What is the student's id number ? "))

# here, diego is a variable ..of type Student ?
diego=Student(name, id)

diego.changeID(id)

diego.print()