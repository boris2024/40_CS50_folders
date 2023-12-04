# TODO


#20230714

while True:
    h0=(input("Height: "))

    if h0.isdecimal()==False:
        continue

    else:

        h=int(h0)

        if h<1 or h>8:
            continue

        else:
            break

for i in range(h):
    print(" "*(h-(i+1)),end="")
    print("#"*(i+1))