print("Round 3")

text=" como joder antes que te jodan, vol 2 "

words=text.split()

print(words)
print()

count=0

for palabra in words:
    if "n" in palabra:
        count+=1
        print(f"found it !!, count={count}, word = {palabra}")

print()