/*utilisation de la
bibliothecque mathematique*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	double depart = -42, nombre = 0;

	nombre = fabs(depart); //valeur absolue, nombre = 42.05
	nombre = ceil(nombre); //desus, arrondi sup, nombre = 43
	nombre -= 1.5; //nombre = 41.5
	nombre = floor(nombre); //desous, arrondi inf, nombre = 41
	nombre = pow(nombre, 2); //puissance, nombre = 1681
	nombre = sqrt(nombre); //racine carree, nombre = 41
	nombre = log(nombre); //ln, nombre = 3.7135
	printf("%d", nombre);

	return 0;
}
