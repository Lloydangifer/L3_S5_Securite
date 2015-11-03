#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int frequence[26];
    int maximum;
    int lettreLaPlusFrequente;
    int key;
    char buffer[1024];
    int k=0;

    for(int j=0;j<26;j++)
    {
        frequence[j]=0;
    }
    while ((i = fgetc(stdin)) != EOF)
    {
        frequence[(i-'A')]++;
        buffer[k]=(unsigned char) i;
        k++;
    }
    buffer[k]='\0'
    /*for(int j=0;j<26;j++) //boucle permettant d'afficher pour chaque lettre sa fréquence dans le texte, utilisé pour débug
    {
        char car=j+'A';
        printf("%c : %d\n",car,frequence[j]);
    }*/
    maximum=frequence[0];
    lettreLaPlusFrequente=0;
    for(int j=1;j<26;j++) //on cherche le 'E', qui est la lettre qui apparait théoriquement le plus de fois.
    {
        if(frequence[j]>maximum)
        {
            maximum=frequence[j];
            lettreLaPlusFrequente=j;
        }
    }
    key=('A'-'E'+lettreLaPlusFrequente)%26;
    i=0;
    printf("clef: %d\n",key);
    while (buffer[i] != EOF)
    {
        unsigned char c = (unsigned char) buffer[i];
        if((c==' ')||(c=='\n'))
        {
            printf("%c", c);
        }
        else
        {
            unsigned char c1 = (unsigned char)buffer[i]-key;
            c1=(c1-'A')%26+'A';
            printf("%c", c1);
        }
        i++;
    }

    return 0;
}
