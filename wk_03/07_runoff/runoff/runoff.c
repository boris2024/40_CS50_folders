#include <cs50.h>
#include <stdio.h>
#include <string.h>
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


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }


    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    // Populate array of candidates

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
            if (!vote(i, j, name))
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
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

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
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;

}   // MAIN ends here


// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    int i=voter;
    int j=rank;

    // k is the index within the candidates array

    for(int k=0; k<candidate_count; k++)
    {
        string s1=  name;
        string s2=  candidates[k].name;

        if(strcmp(s1,s2)==0)
        {
            preferences[i][j]=k;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    int candidate, k;
    // TODO
    for(int i=0; i<voter_count; i++)
    {
        for(int j=0; j<candidate_count; j++)
        {

                    k=preferences[i][j];

                    if( candidates[k].eliminated==false )
                    {
                        candidates[k].votes++;
                        break;
                    }

        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO:

    int half_votes=round(voter_count*0.5);

    for(int k=0; k<candidate_count; k++)
    {
        if(candidates[k].votes>half_votes)
        {
            printf("\n%s\n",candidates[k].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO:

    int minimum_votes=voter_count;

    for(int k=0; k<candidate_count; k++)
    {

        if(!candidates[k].eliminated)
        {
            if( candidates[k].votes<minimum_votes )
            {

                minimum_votes=candidates[k].votes;

            }

        }
    }

    return minimum_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO:

    int count_non_eliminated=0;
    int count_min=0;

    for(int k=0; k<candidate_count; k++)
    {
        if(candidates[k].eliminated==false)
        {
            count_non_eliminated++;
        }
    }

    for(int k=0; k<candidate_count; k++)
    {
        if(candidates[k].votes==min)
        {
            count_min++;
        }
    }

    printf("\n");
    printf("\ncount_min= %i", count_min);
    printf("\ncount_non_eliminated= %i", count_non_eliminated);
    printf("\n");

    if(count_min==count_non_eliminated)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO: FIXME:

    for(int k=0; k<candidate_count; k++)
    {
        if(candidates[k].votes==min)
        {
            candidates[k].eliminated=true;
        }
    }

    return;
}


