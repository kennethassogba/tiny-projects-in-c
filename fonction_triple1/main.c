#include <stdio.h>
#include <stdlib.h>

int triple (int nombre) //fonction triple
    {
        return nombre * 3;
    }
int main ()
    {
        int nombreSaisi = 0;

        printf ("Veillez saisir un entier\n");
        scanf ("%d", &nombreSaisi);

        printf   ("Le triple du nombre que vous qvez saisi est %d\n", triple(nombreSaisi));

        return 0;
    }

