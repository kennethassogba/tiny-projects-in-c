#include <stdio.h>
#include <stdlib.h>

struct noeud_s
{
	int valeur;
	struct noeud_s *gauche;
	struct noeud_s *droit;
};
typedef struct noeud_s* noeud_t;
typedef noeud_t arbre_t;

/*typedef struct elem elem;
struct elem 
{
	int nombre;
	elem *suivant; 
};*/

typedef struct elem_add elem_add;
struct elem_add 
{
	arbre_t arbre;
	elem_add *suivant; 
};

typedef struct file file;
struct file
{
	elem_add *premier;
};


arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit);
arbre_t insert (arbre_t abr, int v);
void affiche_arbre2 (arbre_t arbre);
void affiche_arbre2_rec (arbre_t arbre);
file *ini();
void enfile(file *f, int v);
void enfile_add(file *f, arbre_t abr);
void affichefile(file *f);
void defile(file *f);
void afficher (arbre_t abr);


int main(int argc, char *argv[]) 
{
	arbre_t abr3 = NULL;
	abr3 = cree_arbre(10, NULL, NULL);
	abr3 = insert(abr3, 9);
	abr3 = insert(abr3, 14);
	abr3 = insert(abr3, 6);
	abr3 = insert(abr3, 8);
	abr3 = insert(abr3, 12);
	abr3 = insert(abr3, 17);
	abr3 = insert(abr3, 20);
	afficher (abr3);
	
	return 0;
}


arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit)
{
	arbre_t arbre = malloc(sizeof(struct noeud_s));
	arbre->valeur = valeur;
	arbre->gauche = gauche;
	arbre->droit = droit;
	return arbre;
}

arbre_t insert (arbre_t abr, int v)
{
	if (abr == NULL) //abr vide donc creer
	{
		return cree_arbre(v, NULL, NULL);
	}
	else
	{
		if(v < abr->valeur)
			abr->gauche = insert(abr->gauche, v);
		else if(v > abr->valeur)
			abr->droit = insert(abr->droit, v);
		return abr;
	}
}


void affiche_arbre2_rec (arbre_t arbre)
{
	if (arbre == NULL)
		printf( "_" );
	else
	{
		printf( "{" );
		affiche_arbre2_rec(arbre->gauche);
		printf(",%d,",arbre->valeur);//affiche la valeur du noeud courant
		affiche_arbre2_rec(arbre->droit);
		printf( "}" );
	}
}
void affiche_arbre2 (arbre_t arbre)
{
	affiche_arbre2_rec(arbre);
	printf("\n");
}

//initialiser
file *ini()
{
	file *f = malloc(sizeof(*f));
	if (f!=NULL) 
	{
		f->premier = NULL;
		return f;
	}
	else
	exit(EXIT_FAILURE);
}

//enfile
/*void enfile(file *f, int v)
{
	if(f == NULL)
		return;
	else
	{
		elem *new = malloc(sizeof *new);
		if(new != NULL)
		{
			new->nombre = v;
			if(f->premier == NULL)
			{
				new->suivant = NULL;
				f->premier = new;
			}
			else
			{
				elem *c = f->premier;
				while (c->suivant != NULL)
					c = c->suivant;
				c->suivant = new;
				new->suivant = NULL;
			}
		}
		else
			return;
	}
}*/

//enfiler adresse type arbre
void enfile_add(file *f, arbre_t abr)
{
	if(f == NULL)
		return;
	else
	{
		elem_add *new = malloc(sizeof *new);
		if(new != NULL)
		{
			new->arbre = abr;
			if(f->premier == NULL)
			{
				new->suivant = NULL;
				f->premier = new;
			}
			else
			{
				elem_add *c = f->premier;
				while (c->suivant != NULL)
					c = c->suivant;
				c->suivant = new;
				new->suivant = NULL;
			}
		}
		else
			return;
	}
}

//afficher
void affichefile(file *f)
{
	if (f == NULL)
	{
		exit(EXIT_FAILURE);
	}
	elem_add *act = f->premier;
	while (act != NULL)
	{
		printf("%d\n", act->arbre->valeur);
		act = act->suivant;
	}
	printf("\n");
}

//depiler
void defile(file *f)
{
	if (f == NULL)
	{
		exit(EXIT_FAILURE);
	}
	elem_add *elemD = f->premier;
	if (f != NULL && f->premier != NULL)
	{
		f->premier = elemD->suivant;
		free(elemD);
	}
}


void afficher (arbre_t abr)
{
	//initialiser la file
	file *f = ini();
	arbre_t temp = NULL;
	enfile_add(f, abr); //enfiler abr
	while(f != NULL && f->premier != NULL)
	{
		temp = f->premier->arbre;
		printf("%d\n", f->premier->arbre->valeur);	
		if(temp->gauche != NULL)
			enfile_add(f, temp->gauche); //enfiler abr->gauche
		if(temp->droit != NULL)	
			enfile_add(f, temp->droit); //enfiler abr->droit
		defile(f); //defile abr
	}
}


