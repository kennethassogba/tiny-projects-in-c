#include <stdio.h>
#include <stdlib.h>

//structure
struct noeud_s
{
	int valeur;
	int fe;
	struct noeud_s *gauche;
	struct noeud_s*droit;
};
typedef struct noeud_s* noeud_t;
typedef noeud_t arbre_t;

void menu (void);
arbre_t cree_arbre(int valeur, arbre_t gauche, arbre_t droit);
void affiche_arbre2_rec (arbre_t arbre);
void affiche_arbre2 (arbre_t arbre);
int maxx (int a, int b);
int high (arbre_t arbre);
int calcFact (arbre_t abr);
void majFact (arbre_t abr);
arbre_t insereAVR(arbre_t arbre, int valeur);
arbre_t rotD (/*arbre_t rac, */arbre_t A);
arbre_t rotG (/*arbre_t rac, */ arbre_t A);
arbre_t rotDD (arbre_t A);
arbre_t rotDG (arbre_t A);
arbre_t rotAll (arbre_t A);
void bla(arbre_t A);
arbre_t ajouterMenu (arbre_t avr);


int main(int argc, char *argv[]) 
{
	
	menu();
	return 0;
}

// fonction d'affichage du menu et d'appel des fonctions
void menu (void)
{
	int choix = 0;
	arbre_t A = NULL;
	printf("KA*******************************************************\n");
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("\n");
	printf("-\t\t\tMenu Principal\t\t\t-\n");
	printf("\n");
	printf("*********************************************************\n");
	printf("\n");
	do
	{
		printf("_________________________________________________________\n");
		printf("\n");
		printf("1 - Ajouter un noeud\n");
		printf("2 - Afficher\n");
		printf("3 - Supprimer un noeud\n");
		printf("4 - Quitter\n");
		printf("\n");
		printf("Votre choix? ");
		scanf("%d", &choix);
		switch(choix)
		{
			case 1:
				printf("Vous avez choisi d'ajouter un noeud\n");
				A = ajouterMenu (A);
				break;
			case 2:
				printf("Vous avez choisi d'afficher l'arbre\n");
				affiche_arbre2 (A);
				break;
			case 3:
				printf("(o_o) Bientot disponible (o_o)\n\n");
				break;
			case 4:
				printf("A bientot!\n");
				break;
			default:
				printf("(-_-) Mauvaise idee (-_-) \n\n");
				break;		
		}
	}while(choix != 4);
}



//max de deux nombres
int maxx (int a, int b)
{
	return a>b?a:b;
}
//hauteur d’un arbre
int high (arbre_t arbre)
{
	if(arbre != NULL &&((arbre->gauche == NULL && arbre->droit != NULL)||(arbre->gauche != NULL && arbre->droit == NULL)||(arbre->gauche != NULL && arbre->droit != NULL)))
		return 1 + maxx(high(arbre->gauche), high (arbre->droit));
	else
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

//Afficher les valeurs des nœuds GRD
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

//calcul les facteurs d'equilibrages
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

//mise a jour des facteurs
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

//insertion avec mise a jour des facteurs d'equilibrages
arbre_t insereAVR(arbre_t arbre, int valeur)
{
	if (arbre == NULL)
		arbre = cree_arbre(valeur, NULL, NULL);
	else
	{
		if (valeur < arbre->valeur)
			arbre->gauche = insereAVR(arbre->gauche, valeur);
		else
			arbre->droit = insereAVR(arbre->droit, valeur);
	}
	majFact(arbre);
	return arbre;
}

//rotation droite
arbre_t rotD (arbre_t A)
{
	arbre_t B = A->gauche;
	arbre_t C = B->droit;
	A->gauche = C;
	B->droit = A;
	return B;
}

//rotation gauche
arbre_t rotG (arbre_t A)
{
	arbre_t B = A->droit;
	arbre_t C = B->gauche;
	A->droit = C;
	B->gauche = A;
	return B;
}

//rotation double gauche
arbre_t rotDG (arbre_t A)
{
	A->droit = rotD(A->droit);
	return rotG(A);
}

//rotation double droite
arbre_t rotDD (arbre_t A)
{
	A->gauche = rotG(A->gauche);
	return rotD(A);
}

//cumule toutes les rotations pour equilibrer
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

//indique le type de rotation qui aura lieu
void bla(arbre_t A)
{
	majFact(A);
	if (A->fe > 1)
	{
		if(A->droit->fe == 1)
			printf("Il y a eu rotation simple gauche \n");
		else if (A->droit->fe == -1)
			printf("Il y a eu rotation double gauche \n");				
	}
	else if(A->fe < -1)
	{
		if(A->gauche->fe == -1)
			printf("Il y a eu rotation simple droite \n");
		else if(A->gauche->fe == 1)
			printf("Il y a eu rotation double droite \n");
	}
	else
		printf("Il n'y a pas eu de rotation\n\n");

}

//demande la valuer du noeud a inserer a l'utilisateur
//inserer avec maj des facteurs
//equilibre
arbre_t ajouterMenu (arbre_t avr)
{
	int v = 0;
	printf("Entrez la valeur du noeud a ajouter ");
	scanf("%d", &v);
	avr = insereAVR(avr, v);
	bla(avr);
	avr = rotAll (avr);
	return avr;
}


