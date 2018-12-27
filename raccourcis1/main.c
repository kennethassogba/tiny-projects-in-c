//raccourcis
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	int nombre = 42;

	printf("Nombre au depart = %d\n", nombre);
	nombre++; //incremenation nombre = 43
	nombre--; //decrementation nombre = 42
	nombre += 10; //nombre = 52
	nombre /= 2; //nombre = 26
	nombre -= 15; //nombre = 11
	nombre %= 5; //nombre = 1
	printf("Apres plusieurs opperations raccourcies\n");
	printf("\tnombre = %d\n", nombre);

	return 0;
}
