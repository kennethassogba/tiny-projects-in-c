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
Pile *new(Pile *p, int v);
Pile *dep(Pile *p);
void print(Pile *p);

int main(int argc, char *argv[]) {
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

//empiler
Pile *new(Pile *p, int v)
{
	Element *elt = malloc (sizeof(*elt));
	if(elt!=NULL)
	{
		elt->nombre = v;
		elt->suivant = p ->premier;
		p->premier = elt;
	}
	else
	exit(EXIT_FAILURE);
	
	return p;
}

//depiler
Pile *dep(Pile *p)
{
	int v = 0;
	Element *d = p->premier;
	v = d->nombre;
	(p->premier)=(p->premier)->suivant;
	free(d);
	printf("L'element contenant %d a ete supprime", v);
	return p;
}

//afficher
void print(Pile *p)
{
	if(p == NULL)
	exit(EXIT_FAILURE);
	else
	{
		Element *a = p->premier;
		while(a!=NULL)
		{
			printf("%d/n", a->nombre);
			a = a->suivant;
		}
	}
}
