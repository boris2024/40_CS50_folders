# TODO

from cs50 import get_float
# 20230714

# I did this based on my experience with cash.c

coins_1=0
coins_5=0
coins_10=0
coins_25=0

while True:

    change=get_float("Change owed:")

    if change<=0:
        continue

    else:
        cents=change*100

        mod_25=cents%25

        if (mod_25)==0:
            coins_25=int(cents/25)
            break

        else:
            coins_25=int(cents/25)

            cents_25=cents-25*coins_25
            #print(f"no. of coins, 25 cents= {coins_25}")

            mod_10=cents_25%10

            if (mod_10)==0:
                coins_10=int(cents_25/10)
                break

            else:
                coins_10=int(cents_25/10)

                cents_10=cents_25-10*coins_10

                #print(f"no. of coins, 10 cents= {coins_10}")

                mod_5=cents_10%5

                if(mod_5)==0:
                    coins_5=int(cents_10/5)
                    break

                else:
                    coins_5=int(cents_10/5)
                    cents_5=cents_10-5*coins_5
                    coins_1=cents_5

                    break

coins= coins_1 + coins_5 + coins_10 + coins_25

print(int(coins))
print()
