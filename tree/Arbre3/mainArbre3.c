#include <stdio.h>
#include <stdlib.h>

struct noeud_s
{
	int valeur;
	int fe;
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
void afficheArbreRGD (arbre_t arbre);
noeud_t trouveMin (arbre_t arbre);
void chercheMin (arbre_t arbre);
arbre_t supprAny (arbre_t arbre, int valeur);
void supprMax (arbre_t arbre);
void vide (arbre_t arbre);
int maxx (int a, int b);
int high (arbre_t arbre);
void printHigh (arbre_t arbre);
int deep (arbre_t arbre, int valeur);
void printDeep (arbre_t arbre, int valeur);
int calcFact (arbre_t abr);
void majFact (arbre_t abr);
arbre_t insereAVR(arbre_t arbre, int valeur);
arbre_t rotD (/*arbre_t rac, */arbre_t A);
arbre_t rotG (/*arbre_t rac, */ arbre_t A);
arbre_t rotDD (arbre_t A);
arbre_t rotDG (arbre_t A);
arbre_t rotAll (arbre_t A);
arbre_t rotAll2 (arbre_t A);
arbre_t rotAll3 (arbre_t A);

int main(int argc, char *argv[])
{
	arbre_t abr = NULL;
	int l = 0;
	int c = 0;
	//vide (abr);
	abr = cree_arbre(10, NULL, NULL);
	abr = insereAVR(abr, 9);
	abr = insereAVR(abr, 8);
	//abr = insereAVR(abr, 6);
	affiche_arbre2(abr);
	//abr = rotD (abr);
	abr = rotAll(abr);
	affiche_arbre2(abr);
	detruit_arbre(abr);
	return 0;
}

//Ex1: affiche les éléments d’un arbre suivant le parcours en profondeur préfixe (Racine Gauche Droit, RGD).
void afficheArbreRGD (arbre_t arbre)
{
	if (arbre == NULL)
		printf( "_" );
	else
	{
		printf( "{" );
		printf("%d,",arbre->valeur);
		afficheArbreRGD (arbre->gauche);
		printf(",");
		afficheArbreRGD (arbre->droit);
		printf( "}" );
	}
}

//Ex2 :  dit si un arbre est vide ou non
void vide (arbre_t arbre)
{
	int a = nombre_de_noeuds(arbre);
	if(a == 0)
		printf("L'arbre est vide\n");
	else
		printf("L'arbre n'est pas vide\n");
}

//Ex4: supprime l’élément maximum d’un arbre
void supprMax (arbre_t arbre)
{
	noeud_t max = trouveMax (arbre);
	int v = max->valeur;
	supprAny (arbre, v);
}

//max de deux nombres
int maxx (int a, int b)
{
	return a>b?a:b;
}
//Ex5: hauteur d’un arbre
int high (arbre_t arbre)
{
	if(arbre != NULL &&((arbre->gauche == NULL && arbre->droit != NULL)||(arbre->gauche != NULL && arbre->droit == NULL)||(arbre->gauche != NULL && arbre->droit != NULL)))
	//if (arbre->gauche != NULL && arbre->droit != NULL)
		return 1 + maxx(high(arbre->gauche), high (arbre->droit));
	else
		return 0;
}

void printHigh (arbre_t arbre)
{
	int h = high(arbre);
	printf("La hauteur de l'arbre est %d\n", h);
}

//Ex6: donne la profondeur d’un élément
int deep (arbre_t arbre, int valeur)
{
	if(arbre->valeur != valeur)
	{
		arbre_t pere = trouvePere (arbre, valeur);
		return 1 + deep(arbre, pere->valeur);
	}
	else
		return 0 ;
}

void printDeep (arbre_t arbre, int valeur)
{
	int i = deep (arbre, valeur);
	printf("La profondeur du noeud de valeur %d est %d", valeur, i);
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
	if (valeur < abr2->valeur) // on descend à gauche
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
//Ex3: min et max
noeud_t trouveMax (arbre_t arbre)
{
	if (arbre->droit == NULL)
		return arbre;
	else
		return trouveMax(arbre->droit);
}

noeud_t trouveMin (arbre_t arbre)
{
	if (arbre->gauche == NULL)
		return arbre;
	else
		trouveMin(arbre->gauche);
}

void chercheMax (arbre_t arbre)
{
	noeud_t abr2 = trouveMax(arbre);
	printf ("L'element de valeur %d est le max\n", abr2->valeur);
}

void chercheMin (arbre_t arbre)
{
	noeud_t abr2 = trouveMin(arbre);
	printf ("L'element de valeur %d est le min\n", abr2->valeur);
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

//supprimer un noeud quelconque
arbre_t supprAny (arbre_t arbre, int valeur)
{
	noeud_t abr2 = trouve_noeud(arbre, valeur);
	if (abr2 != NULL)
	{
		//suppr1
		if(abr2->gauche == NULL && abr2->droit == NULL)
		{
			noeud_t pereAbr2 = trouvePere(arbre, valeur);
			if(abr2 == pereAbr2->gauche)
				pereAbr2->gauche=NULL;
			if(abr2 == pereAbr2->droit)
				pereAbr2->droit=NULL;
			free(abr2);
		}
		//suppr2
		else if((abr2->gauche == NULL && abr2->droit != NULL) || (abr2->gauche != NULL && abr2->droit == NULL))
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

		//suppr3
		 else if(abr2->gauche != NULL && abr2->droit != NULL)
		{
			noeud_t maxAbr = trouveMax(abr2->gauche);
			int a = maxAbr->valeur;
			if(maxAbr->gauche == NULL && maxAbr->droit == NULL)
				suppr1(arbre, maxAbr->valeur);
			else if((maxAbr->gauche == NULL && maxAbr->droit != NULL) || (maxAbr->gauche != NULL && maxAbr->droit == NULL))
				suppr2(arbre, maxAbr->valeur);
			abr2->valeur = a;
		}
	}
	else
		printf ("L'element de valeur %d n'a pas ete trouve, il ne peut donc pas etre supprimer\n", valeur);
	return arbre;
}


int calcFact (arbre_t abr)
{
	int fact = 0;
	if(abr == NULL)
		return 0;
	else
	{
		if(abr->gauche == NULL && abr->droit == NULL)
			return 0;
		else if(abr->gauche != NULL && abr->droit == NULL)
			return -high(abr);
		else if(abr->gauche == NULL && abr->droit != NULL)
			return high(abr);
		else if(abr->gauche != NULL && abr->droit != NULL)
		{
			return (high(abr->droit)-high(abr->gauche));
		}
	}
}


void majFact (arbre_t abr)
{
	abr->fe = calcFact (abr);
	if (abr == NULL)
		return;
	if (abr->gauche != NULL)
		majFact(abr->gauche);
	if (abr->droit != NULL)
		majFact(abr->droit);
}

arbre_t insereAVR(arbre_t arbre, int valeur)
{
	if (arbre == NULL)
		arbre = cree_arbre(valeur, NULL, NULL);
	else
	{
		if (valeur < arbre->valeur)
			arbre->gauche = insere(arbre->gauche, valeur);
		else
			arbre->droit = insere(arbre->droit, valeur);
	}
	majFact(arbre);
	return arbre;
}

arbre_t rotD (arbre_t A)
{
	arbre_t B = A->gauche;
	arbre_t C = B->droit;
	A->gauche = C;
	B->droit = A;
	return B;
}

arbre_t rotG (arbre_t A)
{
	arbre_t B = A->droit;
	arbre_t C = B->gauche;
	A->droit = C;
	B->gauche = A;
	return B;
}

arbre_t rotDG (arbre_t A)
{
	A->droit = rotD(A->droit);
	return rotG(A);
}

arbre_t rotDD (arbre_t A)
{
	A->gauche = rotG(A->gauche);
	return rotD(A);
}


arbre_t rotAll (arbre_t A)
{
	majFact(A);
	if (A->fe > 1)
	{
		if(A->droit->fe == 1)
			return rotG (A);
		else if (A->droit->fe == -1)
			return rotDG (A);				
	}
	else if(A->fe < -1)
	{
		if(A->gauche->fe == -1)
			return rotD(A);
		else if(A->gauche->fe == 1)
			return rotDD (A);
	}
	else
		return A;
}

/*arbre_t rotAll2 (arbre_t A)
{
	majFact(A);
	if (A->fe == 2)
	{
		if (A->droit->fe >= 0)
			return rotG(A);
		else
		{
			A->droit = rotD(A->droit);
			return rotG(A);
		}
	}
	else if (A->fe == -2)
	{
		if (A->gauche->fe <= 0)
			return rotD(A);
		else
		{
			A->gauche = rotG(A->gauche);
			return rotD(A);
		}
	}
	else
	return A; 
}*/

arbre_t rotAll3 (arbre_t A)
{
	majFact(A);
	if (A->fe > 1)
	{
		if (A->droit->fe == 1)
			return rotG(A);
		else
		{
			A->droit = rotD(A->droit);
			return rotG(A);
		}
	}
	else if (A->fe < -1)
	{
		if (A->gauche->fe == -1)
			return rotD(A);
		else
		{
			A->gauche = rotG(A->gauche);
			return rotD(A);
		}
	}
	else
	return A; 
}
