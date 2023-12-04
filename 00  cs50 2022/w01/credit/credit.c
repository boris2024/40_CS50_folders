#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
// 1. make sure ccn passes checksum test

long ccn=get_long("Credit card number: ");
printf("\n %li \n",ccn);

int i=0;    // counter
int position=0;
int subtotA=0;
int digit21, digit22;
int subtotB=0;

long ccn2=ccn;
long ccn3=ccn;
long ccn4=ccn;
long ccn5=ccn;

ccn=ccn/10;
do                      // this do-while deals with the even position numbers
{   int digit=ccn%10;
    position=2*(i+1);
    //printf("digit position= %i, digit is=%i\n", position, digit);
    i=i+1;
    ccn=ccn/100;
    subtotA=2*digit;

    digit21=subtotA%10;
    digit22=subtotA/10;

    subtotB=subtotB+digit21+digit22;

} while (ccn>1);

//printf("subtotB=%i\n\n", subtotB);


int digit2;
int subtoteven=0;
int position2;
int j=0;

do          // this do-while deals with the numbers in odd positions
{   digit2=ccn2%10;
    position2=2*(j)+1;
    //printf("digit position= %i, digit is=%i\n", position2, digit2);
    j=j+1;
    ccn2=ccn2/100;
    subtoteven=subtoteven+digit2;

} while (ccn2>1);

//printf("\nsubtoteven=%i\n", subtoteven);

int checksum=subtotB+subtoteven;
printf("checksum= %i\n\n", subtotB+subtoteven);

int lastdigit=checksum%10;

if (lastdigit!=0){printf("INVALID\n");}         // CHECLSUM criteria applied here

else
{

// 2. check for card length and starting digits

int k=0;
do  // divide by 10, count how many times this happens while INT ccn>1
{   ccn3=ccn3/10;
    k=k+1;
} while (ccn3>1);

printf("\nnumber length =%i \n",k);

if (k<13||k==14||k>16){printf("INVALID\n");}

if(k==13)   {   int firstdigits=ccn4/pow(10,12);
                if  (firstdigits==4){printf("\nVISA\n");}
                else{printf("INVALID\n");}
            }


if(k==15)   {   int firstdigits=ccn4/pow(10,13);
                if  (firstdigits==34||firstdigits==37){printf("\nAMEX\n");}
                else{printf("INVALID\n");}
            }



if(k==16)   {   int firstdigits=ccn4/pow(10,14);
                if(firstdigits==51||firstdigits==52||firstdigits==53||firstdigits==54||firstdigits==55)
                {printf("\nMASTERCARD\n");}

                else
                {   firstdigits=ccn5/pow(10,15);
                    if (firstdigits==4){printf("\nVISA\n");}

                    else{printf("INVALID\n");}
                }

            }
}   // CHECKSUM if ends here

}   //MAIN ends here

