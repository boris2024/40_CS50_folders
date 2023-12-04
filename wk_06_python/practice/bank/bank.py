
# 20230705 py practice problems

phrase=input("the greeting was: ")

#print(phrase)

words=phrase.split()

#print(words)

# less than 1 word in greeting
if len(words)<1:
    print("$100")

# more than 0 words in greeting
else:

    palabra=words[0].lower()


    #print(palabra)

    if palabra[0]=="h":
        if palabra=="hello" or palabra=="hello,":
             print("$0")

        elif palabra!="hello":
            print("$20")

        else:
            print("$100")

    else:
        print("$100")