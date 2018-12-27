//mini calculatrice

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a = 0, b = 0, c = 0;

	printf("\tCe programme est une mini calculatrice\n\n");
	printf("Veillez entrer votre premier nombre a :\n"); //demande
	scanf("%d", &a);
	printf("Veillez entrer votre second nombre b :\n");
	scanf("%d", &b);
	c = a + b; //calcul
	printf("%d + %d = %d", a, b, c); //resultat

	return 0;
}
