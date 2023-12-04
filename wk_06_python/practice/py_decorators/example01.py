
# 20230708
# PY program to illustrate functions can be treated as as objects

def shout(text):
    return text.upper()

print(shout("hello"))

yell=shout

print(yell("hello darling"))
