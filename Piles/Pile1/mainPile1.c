#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Element Element;
struct Element 
{
	int nombre;
	Element *suivant; 
};

typedef struct Pile Pile;
struct Pile
{
	Element *premier;
};


Pile *initialiser();
void empiler(Pile *pile, int Nombre);
int depiler(Pile *pile);
void afficherPile(Pile *pile);

int main(int argc, char *argv[]) 
{
	Pile *sPile = initialiser();
	empiler(sPile, 5);
	empiler(sPile, 14);
	empiler(sPile, 25);
	empiler(sPile, 10);
	empiler(sPile, 60);
	printf("\nEtat de la pile :\n");
	afficherPile(sPile);
	printf("Je depile %d\n", depiler(sPile));
	printf("Je depile %d\n", depiler(sPile));
	printf("\nEtat de la pile :\n");
	afficherPile(sPile); 
	
	return 0;
}

//initialisation
Pile *initialiser()
{
	Pile *pile = malloc(sizeof(*pile));
	if (pile!=NULL) 
	{
		pile->premier = NULL;
		return pile;
	}
	else
	exit(EXIT_FAILURE);
}

//empilage
void empiler(Pile *pile, int Nombre)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	if (pile == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = Nombre;
	nouveau->suivant = pile->premier;
	pile->premier = nouveau;
}

//depiler
int depiler(Pile *pile) //retourne l’élément dépilé
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int nombreDepile = 0;
	Element *elementDepile = pile->premier;
	if (pile != NULL && pile->premier != NULL) //si la pile n’est pas vide
	{
		nombreDepile = elementDepile->nombre;
		pile->premier = elementDepile->suivant;
		free(elementDepile);
	}
	return nombreDepile;
}

//afficher
void afficherPile(Pile *pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element *actuel = pile->premier;
	while (actuel != NULL)
	{
		printf("%d\n", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("\n");
}
