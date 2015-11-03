int main(int argc, char *argv[])
{

    int i;
    char *key=argv[1];
    int sizeKey=strlen(key);
    int compteur=0;
    char buffer[1024];


//après avoir trouvé la clef, on déchiffre normalement
    while((i = fgetc(stdin)) != EOF)
    {
        unsigned char c = (unsigned char) i;
        if((c==' ')||(c=='\n'))
        {
            printf("%c", c);
        }
        else
        {
            c=(((c-'A')-(key[compteur%sizeKey]-'A')+26)%26+'A');
            printf("%c", c);
            compteur++;
        }
    }
    return 0;
}

