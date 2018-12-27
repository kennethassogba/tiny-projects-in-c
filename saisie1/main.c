/*Formulaire de recuperation
des notes*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int noteLte = 0, noteAna = 0; //initiatisation

	printf("Quel est votre note en LTE?\n"); //demande la note lte
	scanf("%d", &noteLte); //stock la note de lte
	printf("Quel est votre note en Analyse?\n");
	scanf("%d", &noteAna);
	printf("Votre note en LTE est de %d et votre note en Analyse est de %d. Bah c'est pas du tout le haut niveau!!!\n", noteLte, noteAna);

	return 0;
}
