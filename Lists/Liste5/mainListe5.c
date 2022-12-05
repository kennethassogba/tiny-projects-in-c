#include <stdio.h>
#include <stdlib.h>

/*revision sur les liste
1- fonction concat: concatenation de deux listes
2- fonction fusion: fusion de des elements de 2 listes: L1, L2, L1, L2..
3- fonction revers: inverse une liste
4- fonction produit: produit de des elements de 2 listes: L1*L2, L1*L2..
*/

struct list_entier;
int taille_list (struct  list_entier *L);
struct list_entier *produit (struct list_entier *L1, struct list_entier *L2);
struct list_entier *add_d(struct list_entier *L, int v);
struct list_entier *add_u (struct list_entier * L, int v);
void print (struct list_entier *L);
void list_print (struct list_entier *L);
struct list_entier *concat(struct list_entier *L1, struct list_entier *L2);
struct list_entier *fusion (struct list_entier *L1, struct list_entier *L2);
struct list_entier *revers (struct list_entier *L1);

int main(int argc, char *argv[])
{
	struct list_entier *a = NULL, *b = NULL, *c = NULL, *d = NULL, *e = NULL;

	a = add_d(a, 30);
	a = add_d(a, 20);
	a = add_d(a, 10);
	printf("Liste a\n");
//	printf ("La taille de la liste est %d\n", taille_list(a));
	print (a);
	b = add_d(b, 42);
	b = add_d(b, 18);
	b = add_d(b, 1);
	printf("\n");
	printf("Liste b\n");
//	printf ("La taille de la liste est %d\n", taille_list(b));
	print (b);
	c = concat(a, b);
	printf("\n");
	printf("Concatenation de a et b\n");
	print (c);
	d = fusion (a, b);
	printf("\n");
	printf("Fusion de a et b\n");
	print (d);
	e = revers (a);
	printf("\n");
	printf("Inversion de a\n");
	print (e);

	return 0;
}


struct list_entier
{
int val;
struct list_entier *suivant;
};

int taille_list (struct list_entier *L)
{
	int i=0;
	while (L != NULL)
	{
		L = L->suivant;
		i++;
	}
	return i;
}
//afficher
void print (struct list_entier *L)
{
	int i = 0;
	while(L != NULL)
	{
		printf("Element %d = %d\n", i, L->val);
		L = L->suivant;
		i++;
	}
}

void list_print (struct list_entier *L)
{
int num;
for (num = 0 ; L ; num++)
{
printf("Element %d = %d\n", num, L->val);
L = L->suivant;
}
}

// Inserer en tête de liste
struct list_entier *add_u (struct list_entier * L, int v)
{
	struct list_entier *elt = malloc (sizeof elt);
	elt->val = v;
	elt->suivant = L;
	return elt;
}

// Inserer en fin de liste
struct list_entier *add_d(struct list_entier *L, int v)
{
	struct list_entier *elt = malloc(sizeof elt);
	struct list_entier *c = L;
	elt->val = v;
	if(L == NULL)
	{
		elt->suivant = L;
		return elt;
	}
	else
	{
		while(c->suivant != NULL)
		{
			c = c->suivant;
		}
		c->suivant = elt;
		elt->suivant = NULL;
	}
	return L;
}


struct list_entier *concat(struct list_entier *L1, struct list_entier *L2)
{
	struct list_entier *L = NULL;
	int i = 0, v = 0;
	while(L1 != NULL)
	{
		v = L1->val;
		L = add_d(L, v);
		L1 = L1->suivant;
	}
	while(L2 != NULL)
	{
		v = L2->val;
		L = add_d(L, v);
		L2 = L2->suivant;
	}
	return L;
}

struct list_entier *fusion (struct list_entier *L1, struct list_entier *L2)
{
	struct list_entier *L = NULL;
	int i = 0, v = 0, w = 0;
	while (L1 != NULL && L2 != NULL)
	{
		v = L1->val;
		w = L2->val;
		L = add_d(L, v);
		L = add_d(L, w);
		L1 = L1->suivant;
	    L2 = L2->suivant;
	}
	return L;
}

struct list_entier *revers (struct list_entier *L1)
{
	struct list_entier *L = NULL;
	int i = 0, v = 0;
	while (L1 != NULL)
	{
		v = L1->val;
		L = add_u(L, v);
		L1 = L1->suivant;
	}
	return L;
}

struct list_entier *produit (struct list_entier *L1, struct list_entier *L2)
{
    struct list_entier *tete = NULL;
    while(L1->suivant != NULL)
	{
	    int L = (L1->val)*(L2->val);
	    tete = add_d(tete,L);
	    L1 = L1->suivant;
	    L2 = L2->suivant;
    }
    return tete;
}
