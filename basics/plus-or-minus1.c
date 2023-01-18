//livre du zero, td1, p119
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 1

int main()
{
    int nombreMystere = 0, saisie = 0;

    srand(time(NULL)); //generation du nombreMystere
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    printf("\t\t\t*****PLUS OU MOINS*****\n\n");
    printf("Il s'agira pour vous de determiner un nombre compris entre 1 et 100.\n\n");

    while (saisie != nombreMystere) //tant que l'utilisateur n'a pas trouver le nombre, la boucle se repete
    {
        printf("Quel est le nombre?\n");
        scanf ("%d", &saisie);
        if (saisie < nombreMystere)
        {
            printf ("C'est plus!\n");
        }
        else if (saisie > nombreMystere)
        {
            printf ("C'est moins!\n");
        }
        else
        {
            printf ("\n\n");
            printf ("Bravo, vous avez trouve le nombre mystere !!!\n\n");
        }
    }
    return 0;
}
