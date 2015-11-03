#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    size_t key=atoi(argv[1]);
    while(key>26)
    {
        key-=26;
    }
    while((i = fgetc(stdin)) != EOF)
    {
        unsigned char c = (unsigned char) i;
        if((c==' ')||(c=='\n'))
        {
            printf("%c", c);
        }
        else
        {
            unsigned char c1 = (unsigned char)i+key;
            c1=(c1-'A')%26+'A';
            printf("%c", c1);
        }
    }
    return 0;
}
