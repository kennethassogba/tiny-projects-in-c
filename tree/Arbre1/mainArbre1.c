#include <stdio.h>
#include <stdlib.h>

struct noeud_s
{
	int valeur;
	struct noeud_s *gauche;
	struct noeud_s*droit;
};
typedef struct noeud_s* noeud_t;
typedef noeud_t arbre_t;

arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit);
arbre_t insere(arbre_t arbre, int valeur);
void affiche_arbre2_rec (arbre_t arbre);
void affiche_arbre2 (arbre_t arbre);
int nombre_de_noeuds(arbre_t arbre);
void detruit_arbre(arbre_t arbre);
noeud_t trouve_noeud(arbre_t arbre , int valeur);
void cherche (arbre_t arbre, int valeur);
arbre_t suppr1 (arbre_t arbre, int valeur);
arbre_t trouvePere (arbre_t arbre, int valeur);
void cherchePere (arbre_t arbre, int valeur);
arbre_t suppr2 (arbre_t arbre, int valeur);
noeud_t trouveMax (arbre_t arbre);
void chercheMax (arbre_t arbre);
arbre_t suppr3 (arbre_t arbre, int valeur);

int main(int argc, char *argv[])
{
	arbre_t abr = NULL;
	int l = 0;
	abr = cree_arbre(10, NULL, NULL);
	abr = insere(abr, 9);
	abr = insere(abr, 15);
	abr = insere(abr, 14);
	abr = insere(abr, 17);
	abr = insere(abr, 6);
	abr = insere(abr, 12);
	abr = insere(abr, 20);
	abr = insere(abr, 16);
	affiche_arbre2(abr);
	l = nombre_de_noeuds(abr);
	printf ("La taille de l'arbre est %d\n", l);
	cherche(abr, 100);
	cherche(abr, 9);
	cherche(abr, 00);
	cherche(abr, 10);
	cherche(abr, 15);
	printf ("\n");
	//chercheMax (abr);
	//cherchePere (abr, 17);
	/*abr = suppr1(abr, 100);
	abr = suppr1(abr, 17);
	affiche_arbre2(abr);
	abr = suppr1(abr, 10);
	abr = suppr1(abr, 12);
	affiche_arbre2(abr);
	printf ("\n");*/
	/*abr = suppr2(abr, 17);
	affiche_arbre2(abr);*/
	suppr3(abr, 17);
	affiche_arbre2(abr);
	detruit_arbre(abr);

	return 0;
}



//initialise
arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit)
{
	arbre_t arbre = malloc(sizeof(struct noeud_s));
	arbre->valeur = valeur;
	arbre->gauche = gauche;
	arbre->droit = droit;
	return arbre;
}

//insertion, ajoute une valeur dans l'ABR (ce sera un nouveau nœud placé correctement dans l'arbre)
arbre_t insere(arbre_t arbre, int valeur)
{
	if (arbre == NULL)
		return cree_arbre(valeur, NULL, NULL);
	else
	{
		if (valeur < arbre->valeur)
			arbre->gauche = insere(arbre->gauche, valeur);
		else
			arbre->droit = insere(arbre->droit, valeur);
		return arbre;
	}
}

//Afficher les valeurs des nœuds d'un arbre binaire de manière à lire la structure de l'arbre.
void affiche_arbre2_rec (arbre_t arbre)
{
	if (arbre == NULL)
		printf( "_" );
	else
	{
		printf( "{" );
		affiche_arbre2_rec(arbre->gauche);
		printf(",%d,",arbre->valeur);//affiche la valeur du nœud courant
		affiche_arbre2_rec(arbre->droit);
		printf( "}" );
	}
}
void affiche_arbre2 (arbre_t arbre)
{
	affiche_arbre2_rec(arbre);
	printf("\n");
}

//calcule le nombre de nœuds d'un arbre binaire
int nombre_de_noeuds(arbre_t arbre)
{
	if (arbre == NULL)
		return 0;
	return (1 + nombre_de_noeuds(arbre->gauche) + nombre_de_noeuds(arbre->droit));
}

//détruire un arbre
void detruit_arbre(arbre_t arbre)
{
	if (arbre == NULL)
		return;
	detruit_arbre(arbre->gauche);
	detruit_arbre(arbre->droit);
	free(arbre);
}

//Recherche d’un élément
noeud_t trouve_noeud(arbre_t arbre, int valeur)
{
	if (arbre == NULL)
		return NULL;
	if (valeur == arbre->valeur)
		return arbre;
	if (valeur < arbre->valeur) /* on descend à gauche */
		return trouve_noeud(arbre->gauche,valeur);
	else //on descend à droite
		return trouve_noeud(arbre->droit,valeur);
}

//Recherche d’un élément et dit s'il est present
void cherche (arbre_t arbre, int valeur)
{
	noeud_t abr2 = NULL;
	abr2 = trouve_noeud(arbre, valeur);
	if (abr2 != NULL)
		printf ("L'element de valeur %d a ete trouve\n", abr2->valeur);
	else
		printf ("L'element de valeur %d n'a pas ete trouve\n", valeur);
}

//supprimer une feuille
arbre_t suppr1 (arbre_t arbre, int valeur)
{
	noeud_t abr2 = trouve_noeud(arbre, valeur);
	if (abr2 != NULL)
	{
		//printf ("L'element de valeur %d a ete trouve\n", abr2->valeur);
		if(abr2->gauche == NULL && abr2->droit == NULL)
		{
			noeud_t pereAbr2 = trouvePere(arbre, valeur);
			if(abr2 == pereAbr2->gauche)
				pereAbr2->gauche=NULL;
			if(abr2 == pereAbr2->droit)
				pereAbr2->droit=NULL;
			free(abr2);
		}
		else
			printf ("L'element de valeur %d n'est pas une feuille\n", valeur);
	}
	else
		printf ("L'element de valeur %d n'a pas ete trouve, il ne peut donc pas etre supprimer\n", valeur);
	return arbre;
}

//trouver le pere d'un element
arbre_t trouvePere (arbre_t arbre, int valeur)
{
	noeud_t abr2 = arbre;
	if (abr2 == NULL)
		return NULL;
	if (valeur == (abr2->gauche)->valeur || valeur == (abr2->droit)->valeur)
		return abr2;
	if (valeur < abr2->valeur) /* on descend à gauche */
		return trouvePere(abr2->gauche,valeur);
	else //on descend à droite
		return trouvePere(abr2->droit,valeur);
}

void cherchePere (arbre_t arbre, int valeur)
{
	noeud_t abr2 = trouvePere(arbre, valeur);
	if (abr2 != NULL)
		printf ("L'element de valeur %d ayant pour pere %d a ete trouve\n", valeur, abr2->valeur);
	else
		printf ("L'element de valeur %d n'a pas ete trouve\n", valeur);
}


//supprimer un  noeud ayant un seul fils
arbre_t suppr2 (arbre_t arbre, int valeur)
{
	noeud_t abr2 = trouve_noeud(arbre, valeur);
	if (abr2 != NULL)
	{
		if((abr2->gauche == NULL && abr2->droit != NULL) || (abr2->gauche != NULL && abr2->droit == NULL))
		{
			noeud_t pereAbr2 = trouvePere(arbre, valeur);
			if(abr2 == pereAbr2->gauche)
			{
				if (abr2->gauche != NULL)
					pereAbr2->gauche = abr2->gauche;
				else if (abr2->droit != NULL)
					pereAbr2->gauche = abr2->droit;
			}
			else if(abr2 == pereAbr2->droit)
			{
				if (abr2->gauche != NULL)
					pereAbr2->droit=abr2->gauche;
				else if (abr2->droit != NULL)
					pereAbr2->droit=abr2->droit;
			}
			free(abr2);
		}
		else
			printf ("L'element de valeur %d n'est pas un noeud ayant un seul fils\n", valeur);
	}
	else
		printf ("L'element de valeur %d n'a pas ete trouve, il ne peut donc pas etre supprimer\n", valeur);
	return arbre;
}

noeud_t trouveMax (arbre_t arbre)
{
	if (arbre->droit == NULL)
		return arbre;
	else
		trouveMax(arbre->droit);
}

void chercheMax (arbre_t arbre)
{
	noeud_t abr2 = trouveMax(arbre);
	printf ("L'element de valeur %d est le max\n", abr2->valeur);
}

//supprimer un noeud ayant deux fils
arbre_t suppr3 (arbre_t arbre, int valeur)
{
	noeud_t abr2 = trouve_noeud(arbre, valeur);
	if (abr2 != NULL)
	{
		//printf ("L'element de valeur %d a ete trouve\n", abr2->valeur);
		if(abr2->gauche != NULL && abr2->droit != NULL)
		{
			noeud_t maxAbr = trouveMax(abr2->gauche);
			int a = maxAbr->valeur;
			if(maxAbr->gauche == NULL && maxAbr->droit == NULL)
				suppr1(arbre, maxAbr->valeur);
			else if((maxAbr->gauche == NULL && maxAbr->droit != NULL) || (maxAbr->gauche != NULL && maxAbr->droit == NULL))
				suppr2(arbre, maxAbr->valeur);
			abr2->valeur = a;
		}
		else
			printf ("L'element de valeur %d n'est pas un noeud ayant deux fils\n", valeur);
	}
	else
		printf ("L'element de valeur %d n'a pas ete trouve, il ne peut donc pas etre supprimer\n", valeur);
	return arbre;
}
