#include<cs50.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[4];       // array definition

    people[0].name= "alvaro";
    people[0].number=   "584143374979";

    people[1].name="diego";
    people[1].number="2122574957";

    people[2].name="tete";
    people[2].number="4142499015";

    people[3].name="miranda";
    people[3].number="33848345";

    for(int i=0;i<4;i++)
    {   printf("%s\n",people[i].name);  }

    for(int i=0;i<4;i++)
    {
        if( strcmp(people[i].name,"miranda")==0 ){printf("\n%s\n",people[i].number);
                                                  return 0;              }

    }

    printf("\nnot found\n");
    return 1;

}