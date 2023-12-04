#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])                           //....MAIN STARTS HERE
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))                          //VOTE FXN
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates       //TABULATE FXN
        tabulate();

        // Check if election has been won
        bool won = print_winner();                          //PRINT WINNER FXN
        if (won)
        {   break;  }


        // Eliminate last-place candidates
        int min = find_min();                               //FIND MIN FXN

        bool tie = is_tie(min);                             //IS TIE FXN


        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);                                         //ELIMINATE FXN

        /**/

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {   candidates[i].votes = 0;    }

    }
return 0;
}                               // MAIN ENDS here

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int i=voter, j=rank;
    for (int k=0;k<candidate_count;k++)
    {   if(strcmp(name,candidates[k].name)==0)  {preferences[i][j]=k;
                                                 return true;        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

for(int i=0;i<voter_count;i++)      // scan the preferences array vertically, the voters
{
    for(int j=0;j<candidate_count;j++)      // scan the preferences array horizontally, the ranks
    {   //if(j>=1){break;}

            int k=preferences[i][j];
            if(candidates[k].eliminated==false){candidates[k].votes++;
                                                    break;   }
        }
    }
}




// Print the winner of the election, if there is one
bool print_winner(void)
{
    for(int k=0; k<candidate_count; k++)
    {   printf("\ncandidate %i, votes= %i\n",k,candidates[k].votes);    }

    float voters2=voter_count;
    float halfvotes=voters2/2;

    //printf("\nhalfvotes=%f\n",halfvotes);


    for(int k=0; k<candidate_count; k++)
    {   if(candidates[k].votes>halfvotes)
        {printf("\n%s\n",candidates[k].name);return true;}
    }


    return false;
}


// Return the minimum number of votes any remaining candidate has
int find_min(void)
{   int minvotes=100;
    int counter=0;

        for(int k=0; k<candidate_count;k++)
        {           if(candidates[k].votes<minvotes&&candidates[k].eliminated==false)
                    {   minvotes=candidates[k].votes;
                    }
        }

        /*
        for(int k=0; k<candidate_count;k++)
        {   if(candidates[k].votes==minvotes)
            {   counter++;
                printf("\ncandidate %s,min votes=%i\n",candidates[k].name, candidates[k].votes);
            }
        }
        */

        for(int k=0; k<1;k++)
        {   return minvotes;

        }

printf("\n");

return 0;
}




// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int minvotes=min;

    int countercondition=0;
    int counter=0;

    for(int k=0;k<candidate_count;k++)
    {
        if(candidates[k].eliminated==false&&candidates[k].votes==min)
            { countercondition++;}
    }

    for(int k=0;k<candidate_count;k++)
    {
        if(candidates[k].eliminated==false){ counter++;}
    }

    printf("\ncountercondition=%i\n",countercondition);
    printf("\ncounter=%i\n",counter);

    if(counter!=countercondition)
        {printf("\nthey are NOT the same, there is no tie\n"); return false;}

    printf("\nwe have a tie\n");
return true;
}


// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int k=0; k<candidate_count;k++)
    {
        if(candidates[k].votes==min)
        {   candidates[k].eliminated=true;
        }
    }

}
/**/