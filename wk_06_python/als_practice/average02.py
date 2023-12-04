from cs50 import get_int

scores=[]

for i in range(4):
    mark=get_int("what is the score to include? ")

    scores.append(mark)

    average=sum(scores)/len(scores)

    print(f"average so far= {average}")


