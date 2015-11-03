#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        fprintf(stderr, "Error: Not Enough Parameter !\n");
        return 1;
    }

    int i;
    char *key=argv[1];
    int sizeKey=strlen(key);
    int compteur=0;

    while((i = fgetc(stdin)) != EOF)
    {
        unsigned char c = (unsigned char) i;
        if((c==' ')||(c=='\n'))
        {
            printf("%c", c);
        }
        else
        {
            c=(((c-'A')+(key[compteur%sizeKey]-'A'))%26+'A');
            printf("%c", c);
            compteur++;
        }
    }
    return 0;
}
