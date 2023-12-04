#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{   int winner;
    int loser;  } pair;

// Array of candidates
string candidates[MAX];                 //! 1D array of CANDIDATES
pair pairs[MAX * (MAX - 1) / 2];        //! is this array 1D or 2D ?

int pair_count;                         //! GLOBAL VARIABLES 1 and 2
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);

int main(int argc, string argv[])       // ! MAIN starts here, CLA are used
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {       printf("Maximum number of candidates is %i\n", MAX);
            return 2;    }

    for (int i = 0; i < candidate_count; i++)
    {    candidates[i] = argv[i + 1];    }


    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {    locked[i][j] = false;   }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {

        // ranks[k] is the voter's k th preference,
        // this is an array filled with the corresponding int index from the candidates array

        int ranks[candidate_count];                         // ! THIS IS AN ARRAY of INT

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))                      // ! FXN CALL 01, vote
            {   printf("Invalid vote.\n");
                return 3;    }
        }


        record_preferences(ranks);                          // ! FXN CALL 02, record preferences

        printf("\n");
    }

  //! from this point on, alvaro added code

        for(int i=0;i<candidate_count;i++)
        {
            for(int j=0; j<candidate_count;j++)
            {
                printf("\ni=%i, j=%i, preferences[i][j]=%i",i,j,preferences[i][j]);
            }

        }

printf("\n");


    add_pairs();

    for(int k=0;k<pair_count;k++)
    {
       // printf("\npairs[%i] winner =%i",k,pairs[k].winner);
        //printf("\npairs[%i] loser =%i\n",k,pairs[k].loser);
        printf("\npreferences[%i][%i]=%i\n",pairs[k].winner,pairs[k].loser,preferences[pairs[k].winner][pairs[k].loser]);
    }
    printf("\n");


    sort_pairs();

     for(int k=0;k<pair_count;k++)
    {
        //printf("\npairs[%i] winner =%i",k,pairs[k].winner);
        //printf("\npairs[%i] loser =%i\n",k,pairs[k].loser);
        printf("\npreferences[%i][%i]=%i\n",pairs[k].winner,pairs[k].loser,preferences[pairs[k].winner][pairs[k].loser]);
    }
    printf("\n");
    printf("\n");

/*
    lock_pairs();
    print_winner();
    return 0;
*/


}   // !! MAIN ENDS HERE


// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])           //! VOTE FXN, TODO
{
    int j=rank;

    for(int i=0;i<candidate_count;i++)      //! this FOR LOOP scans over the candidates array
    {
            if(strcmp(name,candidates[i])==0)
                {   ranks[j]=i; return true;    }   //! if there is a match i is assgined to ranks[j]
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])                    //! record_preferences FXN
{
for(int i=0;i<candidate_count;i++)
{
    for(int j=0;j<candidate_count;j++)
    {
        for(int k=1;k<candidate_count;k++)
        {
            if(ranks[0]==i&&ranks[k]==j){preferences[i][j]++;}
        }
    }

}
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)                                    //! FXN add_pairs
{   pair_count=0;

for(int i=0; i<candidate_count; i++ )
{
    for(int j=0; j<candidate_count; j++)
    {
        if(preferences[i][j]!=0)        //FIRST CONDITION find which elements from the preferences array are not zero
        {
            if(preferences[i][j]!=preferences[j][i])    // 2ND condition, exclude all ties
            {
                printf("\n\ncounter=%i\n",pair_count);
                printf("\npreferences !0 AND NOT tied,  [i]=%i, [j]=%i\n",i,j);

                pairs[pair_count].winner=i;
                pairs[pair_count].loser=j;

                pair_count++;
            }
        }
    }
}

printf("\n3rd fxn \n");
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

for(int j=0; j<pair_count; j++)

{
    for(int k=j; k<(pair_count-1); k++ )    //! this FOR controls the particular swaps, in every scan
    {   if
        (preferences[pairs[k].winner][pairs[k].loser] <
            preferences[pairs[k+1].winner][pairs[k+1].loser])

        {   int swap=pair_count+1;

            pairs[swap]=pairs[k+1];
            pairs[k+1]=pairs[k];
            pairs[k]=pairs[swap];
        }

        else{}

    }
}

}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;  //!
}