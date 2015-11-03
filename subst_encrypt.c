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
    char* key=argv[1];
    char* keyClean=malloc(sizeof(key)); // Clé sans doublons
    keyClean[0]='\0';
    char charTmp[2];
    charTmp[1]='\0';
    char substTable[27]; //table de substitution
    substTable[0]='\0';
    // Suppression des doublons dans la clé
    for(size_t i=0;i<strlen(key);i++)
    {
        if(strchr(keyClean,key[i])==NULL)
        {
            charTmp[0]=key[i];
            strcat(keyClean,charTmp);
        }
    }
    // Remplissage de la table de substitution
    strcat(substTable,keyClean);
    for(int i=0;i<26;i++)
    {
        if(strchr(substTable,i+'A')==NULL)
        {
            charTmp[0]=(char)(i+'A');
            strcat(substTable,charTmp);
        }
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
            c=(substTable[c-'A']);
            printf("%c", c);
        }
    }
    free(keyClean);
    return 0;
}
