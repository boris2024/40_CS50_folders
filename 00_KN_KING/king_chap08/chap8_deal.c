#include<cs50.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<time.h>
#include<stdbool.h>

/* program deal.c from KN KING's "C programming, a modern approach"
page 173
*/

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
bool in_hand[NUM_SUITS][NUM_RANKS]={false};

int num_cards, rank, suit;

const char rank_code[]={'a','2','3','4','5','6','7','8','9','j','q','k'};

const char suit_code[]={'C','D','H','S'};

srand ((unsigned) time(NULL));

printf("\nenter number of cards in hand:\n");
scanf("%d", &num_cards);

printf("\nyour hand:\n");

while(num_cards > 0)
{
    suit = rand() % NUM_SUITS;
    rank = rand() % NUM_RANKS;

    if(!in_hand[suit][rank])
    {
        in_hand[suit][rank]=true;
        num_cards--;
        printf("     %c %c", rank_code[rank], suit_code[suit]);
    }
}

printf("\n");

return 0;
}// MAIN ends here

