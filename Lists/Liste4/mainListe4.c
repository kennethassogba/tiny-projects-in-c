#include <stdio.h>
#include <stdlib.h>

//Exercices sur les listes circulaires doublement chainees

typedef struct elt
{
	int val; /* données quelconques */
	struct elt* precedent; /* pointeur sur l'élément précédent */
	struct elt* suivant; /* pointeur sur l'élément suivant */
}LCDC;

//structure repère
typedef struct ListeRepere
{
	int taille;
	LCDC *debut;
	LCDC *fin;
}Liste;

Liste *initialisation (void);
void affiche (Liste * liste);
int insertVide(Liste *liste, int donnee);
int insert(Liste * liste, LCDC *courant, int donnee);
void tailleListe (Liste *liste);
void supprimerElement(Liste *t, LCDC *element);
Liste *apresP(Liste *p_list, int data1, int data2);
Liste *List_remove(Liste *p_list,int val);
void deleteListe(Liste **liste);

int main(int argc, char *argv[])
{
	Liste *ad = NULL;
	ad = initialisation ();
	insertVide(ad, 10);
	affiche(ad);
	printf("\n");

	insert(ad, ad->fin, 20);
	affiche(ad);
	printf("\n");
	//tailleListe(ad);

	ad = apresP(ad, 20, 30);
	affiche(ad);
	printf("\n");
	//tailleListe(ad);

	ad = apresP(ad, 20, 25);
	affiche(ad);
	printf("\n");

	ad = List_remove(ad, 20);
	affiche(ad);
	printf("\n");

	deleteListe(&ad);
	printf("Fin\n");

	return 0;
}

//initialisation
Liste *initialisation (void)
{
	Liste *element= (Liste *) malloc(sizeof(Liste));

	if (element!= NULL)
	{
		element->debut= NULL;
		element->fin = NULL;
		element->taille = 0;
	} return element;
}

/* affichage de la liste */
void affiche (Liste * liste)
{
	LCDC *courant;
	courant = liste->debut;
	int i;
	for(i=0; i < (liste->taille); ++i)
	{
		printf ("L'element %d est %d \n", i, courant->val);
		courant = courant->suivant;
	}
}

// taille de la liste
void tailleListe (Liste *liste)
{
	int t = 0;
	t = liste->taille;
	printf("La taille de la liste est %d\n", t);
}

/* insertion dans une liste vide */
int insertVide(Liste *liste, int donnee)
{
	LCDC *nouveau_element;
	nouveau_element = (LCDC *) malloc(sizeof(LCDC));
	if (nouveau_element == NULL)
		return -1;
	if (nouveau_element != NULL)
	{
		nouveau_element->val = donnee;
		nouveau_element->suivant = nouveau_element;
		liste->debut = nouveau_element;
		liste->fin = nouveau_element;
		liste->taille++;
	}
	return 0;
}

/* insertion dans une liste non-vide, insertion en fin de liste */
int insert(Liste * liste, LCDC *courant, int donnee)
{
	LCDC *nouveau_element;
	nouveau_element= (LCDC *) malloc(sizeof(LCDC));
	if (nouveau_element== NULL)
		return -1;
	if (nouveau_element!= NULL)
	{
		if(courant != liste->fin)
			return -1;
		nouveau_element->val = donnee;
		nouveau_element->suivant = courant->suivant;
		nouveau_element->precedent = courant;
		courant->suivant->precedent = nouveau_element;
		courant->suivant = nouveau_element;
		liste->fin = nouveau_element;
		liste->debut->precedent = nouveau_element;
		liste->taille++;
	}
	return 0;
}

//suppression du premier ou du dernier élément
void supprimerElement(Liste *t, LCDC *element)
{
	if (t->debut == element)
	{
		element->precedent->suivant = element->suivant;
		element->suivant->precedent = element->precedent;
		t->fin->suivant = t->debut->suivant;
		t->debut->suivant->precedent = t->debut->precedent;
		t->debut = t->debut->suivant;
		free(element);
		t->taille--;
	}
	if (t->fin == element)
	{
		element->precedent->suivant = element->suivant;
		element->suivant->precedent = element->precedent;
		t->fin->precedent->suivant = t->debut;
		t->debut->precedent = t->fin->precedent;
		t->fin = t->fin->precedent;
		free(element);
		t->taille--;
	}
}

//ajout de data2 apres P (data1)
Liste *apresP(Liste *p_list, int data1, int data2)
{
    if(p_list!=NULL)/*On vérifie si notre liste a été allouée*/
    {
		LCDC *p_temp = p_list->debut;
		//int found=0;
		while(p_temp != NULL && p_temp->val != data1 /*&&!found*/)
			p_temp = p_temp->suivant;
		if(p_temp->val == data1)
	    {
	        LCDC *p_new = malloc(sizeof *p_new);/*Création d'un nouveau LCDC*/
	        if(p_new != NULL) /*On vérifie si le malloc n'a pas échoué*/
	        {
	            if(p_temp->suivant == p_list->debut)
	            {

	            	//printf("La valeur du dernier element est %d et p est : %d \n", p_temp->val, data1);
	            	//insert(p_list, p_list->fin, data2);
	                p_new->val = data2;
					p_new->suivant = p_temp->suivant;
					p_new->precedent = p_temp;
					p_temp->suivant->precedent = p_new;
					p_temp->suivant = p_new;
					p_list->fin = p_new;
					p_list->debut->precedent = p_new;
					//p_list->debut = p_new->suivant;
					//printf("Le premier element est %d\n", p_list->debut->val);
					//printf("Le dernier element est %d\n", p_list->fin->val);

					//p_list->taille++;
					//printf("La taille dans insertion est %d\n", p_list->taille);


	            }
	            else
	            {
	                //apres P
	                p_new->val = data2; /*On 'enregistre' notre donnée*/
	                p_new->suivant = p_temp->suivant;
	                p_temp->suivant = p_new;
	                p_new->precedent = p_temp;
	            }
	        }
	        //found=1;
	    }
    }
p_list->taille++;/*Incrémentation de la taille de la liste*/
return p_list; /*on retourne notre nouvelle liste*/
}

//Suppression d’un élément de la liste selon sa valeur
Liste *List_remove(Liste *p_list,int val)
{
    if(p_list!=NULL)
    {
        LCDC *p_temp=p_list->debut;
        int found=0;
        while(p_temp->suivant != p_list->debut&&!found)
        {
            if(p_temp->val == val)
            {
                if(p_temp->suivant == p_list->debut)
                {
                    p_list->fin = p_temp->precedent;
                    p_list->fin->suivant = p_list->debut;
                }
                else if(p_temp->precedent== p_list->fin)
                {
                    p_list->debut=p_temp->suivant;
                    p_list->debut->precedent=p_list->fin;
                }
                else
                {
                    p_temp->suivant->precedent=p_temp->precedent;
                    p_temp->precedent->suivant=p_temp->suivant;
                }
                free(p_temp);
                p_list->taille--;
                found=1;
            }
            else
            {
            p_temp=p_temp->suivant;
            }
        }
    }
    return p_list;
}

void deleteListe(Liste **liste)
{
	if(*liste!=NULL)
	{
		LCDC *p_temp=(*liste)->debut;
		while(p_temp->suivant != (*liste)->debut)
		{
			LCDC *p_del=p_temp;
			p_temp=p_temp->suivant;
			free(p_del);
		}
		free(*liste);
		*liste=NULL;
	}
}
