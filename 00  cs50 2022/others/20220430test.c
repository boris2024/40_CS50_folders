#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
// this is the FIRST filter
    if(argc!=2) {   printf("\nError 01 Usage: ./substitution (26-char alphabetic key)\n");
                    return 1;
                }

// this is the SECOND filter
string key=argv[1];
int length= strlen(key);

// filter 2.1 key must contain only 26 char
if(length!=26)  {   printf("\nError 02: key must contain 26 char\n");
                    return 1;
                }

string alphabet="abcdefghijklmnopqrstuvwxyz";

printf("\n");

string plain=get_string("plaintext:");

int plainlength=strlen(plain);
int p=plainlength;
char cipher[p];     // ciphertext array declared, same length as plaintext


printf("ciphertext:");

for(p=0;p<plainlength;p++)
{

    if(!isalpha(plain[p]))      // this is the case where plain[p] char are not alphabetic
    {   int c=p;
        cipher[c]=plain[p]; }


    else                        // for all alphabetic chars in plain[p]

    {   if(islower(plain[p]))
        {   for(int i=0;i<26;i++)
            {       if(alphabet[i]==(plain[p]))
                    {   int j=i;
                        cipher[p]=tolower(key[j]);   }
            }
        }

        else
        {   for(int i=0;i<26;i++)
            if(alphabet[i]==tolower(plain[p]))
                {   int j=i;
                    cipher[p]=toupper(key[j]);   }
        }
    }

printf("%c",cipher[p]);

}
printf("\n");
return 0;
}   // MAIN ends here