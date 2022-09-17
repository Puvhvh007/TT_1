#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFSIZE 128

//variables
char InputString[BUFFSIZE];
char OutputString[BUFFSIZE];

//prototypes
void Convert(char* String);
int strcasestr(const char *str, const char *pattern);

int main()
{
    while(1)
    {
        printf("Type the input string: ");
        gets(InputString);
        Convert(InputString);
        printf("'%s' => '%s'\n\n", InputString, OutputString);
        memset(InputString,0,strlen(InputString));
        memset(OutputString,0,strlen(OutputString));
    }
}

void Convert(char* String)
{
    char Buffer[BUFFSIZE];
    int StringLength, i, f= 0;
    StringLength = strlen(String);

    for(i=0; i<StringLength; i++)
    {
        Buffer[i]= toupper((unsigned char)String[i]);
        OutputString[i]=toupper((unsigned char)String[i]);
    }

    for(i=0; i<StringLength; i++)
    {
        for(f=0; f<StringLength; f++)
        {
            if((Buffer[f]==Buffer[i])&&(f!=i))
            {
                OutputString[i]=')';
                OutputString[f]=')';
                break;
            }
            else
            {
                OutputString[i]='(';
            }
        }
    }
}

