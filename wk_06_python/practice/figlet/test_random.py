
# 20230706

import sys
import random

from sys import argv

from pyfiglet import Figlet

figlet = Figlet()

text=input("what is the text to print ?")

list=figlet.getFonts()

print(f"no. elements in list= {len(list)}")


a=0
b=len(list)-1

print(list[a])
print(list[b])

x=random.randint(a,b)

print(f"random x={x}")
print()
print(list[x])

#figlet.setFont(font=font_name)
print()
#print(figlet.renderText(text))

