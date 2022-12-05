#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix = 0;

    printf("=== Menu ===\n");
    printf("1. Royal Cheese\n");
    printf("2. Mc Deluxe\n");
    printf("3. Mc Bacon\n");
    printf("4. Big Mac\n");
    printf("Votre choix ?\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("Tu as choisi le menu Royal Cheese\n");
        break;

    case 2:
        printf("Tu as choisi le menu Mc Deluxe\n");
        break;

    case 3:
        printf("Tu as choisi le menu Mc Bacon\n");
        break;

    case 4:
        printf("Tu as choisi le menu Big Mac\n");
        break;
    default:
        printf("Tu devrais choisir un nombre compris entre 1 et 4\n");
    }

    return 0;
}
