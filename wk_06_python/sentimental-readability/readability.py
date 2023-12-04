# TODO

# 20230715

from cs50 import get_string

# Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8

# L = average number of letters per 100 words
# S = average number of sentences per 100 words

text=get_string("write text to analyze: ")

# this is the total number of characters in the text
total_char=len(text)

char_lower=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

char_upper=[x.upper() for x in char_lower]


letter_count=0

for character in text:
    if (character in char_lower) or (character in char_upper):
        letter_count+=1

#print(letter_count)

space=" "

space_count=0
for character in text:
    if character==space:
        space_count+=1

word_count=space_count+1


end_character_count=0

for character in text:
    if (character==".") or (character=="!") or (character=="?"):
        end_character_count+=1


L=(letter_count/word_count)*100

S=(end_character_count/word_count)*100

# Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8

index0=(0.0588 * L - 0.296 * S - 15.8)

index=int(round(index0,0))

if index<1:
    print("Before Grade 1")

else:
    if(index>=16):
        print("Grade 16+")

    else:
        print(f"Grade {index}")