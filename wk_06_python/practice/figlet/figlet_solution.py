import sys
import random
from pyfiglet import Figlet

# source: https://www.reddit.com/r/cs50/comments/wfsogp/failing_check50_but_im_pretty_sure_the_codes/


# Figlet Vars
figlet = Figlet()
figList = figlet.getFonts()


# 0 Argument Action
if len(sys.argv) == 1:
    user_input = str(input("Input: "))
    # Gets users word
    rf = random.choice(figList)
    # Gets Font List and Chooses Random Font from list
    figlet.setFont(font=rf)
    # Sets Font
    print('Output: ')
    print(figlet.renderText(user_input))
    # Renders users input with set font


# 1 Argument Test Case
if len(sys.argv) == 2:
    print("Invalid Usage")
    sys.exit()


# 2 Arguments Action
if len(sys.argv) == 3:
    if "-f" != sys.argv[1] != "--font":
        # Test to ensure proper -f / --font args
        print("Invalid usage")
        sys.exit()
    else:
        if sys.argv[2] in figList:
            # Ensures inputted font is a selectable font
            user_input = str(input("Input: "))
            # Gets users Input
            figlet.setFont(font=sys.argv[2])
            # Sets Font
            print('Output: ')
            print(figlet.renderText(user_input))
            # Renders users input with set font
        else:
            # "If font is not a selectable font, do this"
            print("Invalid usage")
            sys.exit()

# 3 or More Argument Test Case
if len(sys.argv) > 3:
    print("Invalid Usage")
    sys.exit()