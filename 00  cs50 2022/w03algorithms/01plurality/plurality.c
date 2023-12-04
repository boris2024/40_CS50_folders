#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9                       // Max number of candidates

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;


candidate candidates[MAX];          // Array of candidates

int candidate_count;                // Number of candidates

bool vote(string name);             // Function prototypes
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {   printf("Maximum number of candidates is %i\n", MAX);
        return 2;   }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))                    // Check for invalid vote
        {   printf("Invalid vote.\n");  }
    }

    //Display winner of election

    print_winner();

}   // MAIN ends here


// Update vote totals given a new vote
bool vote(string name)
{
    for(int i=0;i<candidate_count; i++)
    {
        if( strcmp(candidates[i].name,name)==0  )
        {   candidates[i].votes++;
            return true;              }
    }

    return false;
}


// Print the winner (or winners) of the election

void print_winner(void)
{

for(int i=0; i<candidate_count;i++)
{   int counter=0;

//increment once every time comparison is TRUE
    for(int j=0; j<candidate_count; j++)
    {
        if ((candidates[i].votes)>(candidates[j].votes))
        {   counter++;
            // case A= just 1 winner, no ties
            if((candidate_count-1)==counter)   {printf("%s",candidates[i].name);
                                                break;
                                                return;
                                                }
        }
    }


}

printf("\n");
return ;
}