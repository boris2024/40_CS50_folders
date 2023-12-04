
# 20230706 9.08 pm

import sys
import random

from sys import argv

from pyfiglet import Figlet

figlet = Figlet()


if len(argv)==1 or len(argv)==3:

    # user wants to output text in random font
    if len(argv)==1:
        #print("user wants random font")

        text=input("random font option, What is the text to print? ")

        list=figlet.getFonts()

        a=0
        b=len(list)-1

        x=random.randint(a,b)

        print(f"random x={x}")
        print()
        print(list[x])

        figlet.setFont(font=list[x])
        print(figlet.renderText(text))

        print()


    # user wants to use specific font
    elif len(argv)==3:

        font_name=argv[2]

        if (argv[1]=="-f" or argv[1]=="--font"):
            #print(f"name of selected font: {font_name}")

            text=input("please enter text to print in ASCII art: ")

            if font_name not in figlet.getFonts():
                print("Invalid Usage, not on list of names")
                sys.exit("Invalid Usage")

            else:
                figlet.setFont(font=font_name)
                print()
                print(figlet.renderText(text))


        elif (argv[1]!="-f" or argv[1]!="--font"):
            #print("Invalid Usage")
            sys.exit("Invalid Usage")

    # include missing condition here

else:
    #print("Invalid Usage")
    sys.exit("Invalid Usage")