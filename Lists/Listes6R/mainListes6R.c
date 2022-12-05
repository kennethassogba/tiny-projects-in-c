#include <stdio.h>
#include <stdlib.h>

//definition
struct node
{
    int data;   //donnée associée à l’élément
    struct node *p_next;  //désigne l’élément suivant
    struct node *p_prev;  //désigne l’élément précédant
};

//definition
typedef struct dlist
{
    int length;
    struct node *p_tail;
    struct node *p_head;
}Dlist;

Dlist *dlist_new(void);
Dlist *dlist_append(Dlist *p_list,int data);
Dlist *dlist_prepend(Dlist *p_list,int data);
Dlist *dlist_remove(Dlist *p_list,int data);
void dlist_delete(Dlist **p_list);
void print (Dlist *p_list);
Dlist *concat2 (Dlist *L1, Dlist *L2);
Dlist *fusion2 (Dlist *L1, Dlist *L2);
void *maxx(Dlist *L);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	Dlist *t = NULL, *u = NULL, *v = NULL, *w = NULL;
	t = dlist_new();
	u = dlist_new();
	v = dlist_new();
	w = dlist_new();
	
	t = dlist_append(t, 30);
	t = dlist_append(t, 40);
	t = dlist_append(t, 50);
	printf("Liste1\n");
	print (t);
	maxx(t);
	printf("\n");
	
	u = dlist_append(u, 10);
	u = dlist_append(u, 20);
	u = dlist_append(u, 42);
	printf("Liste2\n");
	print (u);
	maxx(u);
	printf("\n");
	
	/*v = concat2(t, u);
	printf("Concatenation des listes 1 et 2\n");
	print(v);
	
	w = fusion2(t, u);
	printf("fusion des listes 1 et 2\n");
	print(w);*/
	return 0;
}


//creation
Dlist *dlist_new(void)

{
    Dlist *p_new=malloc(sizeof *p_new);
    if(p_new!=NULL)
    {
        p_new->length=0;
        p_new->p_head=NULL;
        p_new->p_tail=NULL;
    }
    return p_new;
}

//ajouter un element
Dlist *dlist_append(Dlist *p_list,int data)
{
    if(p_list!=NULL)/*On vérifie si notre liste a été allouée*/
    {
        struct node *p_new=malloc(sizeof *p_new);/*Création d'un nouveau node*/
        if(p_new!=NULL)/*On vérifie si le malloc n'a pas échoué*/
        {
            if(p_list->p_tail==NULL)/*Cas où notre liste est vide(pointeur vers fin de liste à NULL)*/
            {
                p_new->data=data;/*On 'enregistre' notre donnée*/
                p_new->p_next=NULL;/*On fait pointer p_next vers NULL*/
                p_new->p_prev=NULL;/*On fait pointer p_prev vers NULL*/
                p_list->p_head=p_new;/*On fait pointer la tête de liste vers le nouvel élément*/
                p_list->p_tail=p_new;/*On fait pointer la fin de liste vers le nouvel élément*/
            }
            else/*Cas où des éléments sont déjà présents dans notre liste*/
            {
                p_new->data=data;/*On'enregistre'notredonnée*/
                p_new->p_next=NULL;/*Onfaitpointerp_nextversNULL*/
                p_list->p_tail->p_next=p_new;/*On relie le dernier élément de la liste vers notre nouvel élément*/
                p_new->p_prev=p_list->p_tail;/*On fait pointer p_prev vers le dernier élément de la liste*/
                p_list->p_tail=p_new;/*On fait pointer la fin de liste vers notre nouvel  élément*/
            }
            p_list->length++;/*Incrémentation de la taille de la liste*/
        }
    }
    return p_list;/*on retourne notre nouvelle liste*/
}

//ajouter un elem au debut
Dlist *dlist_prepend(Dlist *p_list,int data)
{
    if(p_list!=NULL)
    {
        struct node *p_new=malloc(sizeof *p_new);
        if(p_new!=NULL)
        {
            if(p_list->p_tail==NULL)
            {
                p_new->data=data;
                p_new->p_prev=NULL;
                p_new->p_next=NULL;
                p_list->p_head=p_new;
                p_list->p_tail=p_new;
            }
            else
            {
                p_new->data=data;
                p_new->p_prev=NULL;
                p_list->p_head->p_prev=p_new;
                p_new->p_next=p_list->p_head;
                p_list->p_head=p_new;
            }
            p_list->length++;
        }
    }
    return p_list;
}

//Suppression d’un élément de la liste selon sa valeur
Dlist *dlist_remove(Dlist *p_list,int data)
{
    if(p_list!=NULL)
    {
        struct node *p_temp=p_list->p_head;
        int found=0;
        while(p_temp!=NULL&&!found)
        {
            if(p_temp->data==data)
            {
                if(p_temp->p_next==NULL)
                {
                    p_list->p_tail=p_temp->p_prev;
                    p_list->p_tail->p_next=NULL;
                }
                else if(p_temp->p_prev==NULL)
                {
                    p_list->p_head=p_temp->p_next;
                    p_list->p_head->p_prev=NULL;
                }
                else
                {
                    p_temp->p_next->p_prev=p_temp->p_prev;
                    p_temp->p_prev->p_next=p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
                found=1;
            }
            else
            {
            p_temp=p_temp->p_next;
            }
        }
    }
    return p_list;
}

//Libérer une liste
void dlist_delete(Dlist **p_list)
{
    if(*p_list!=NULL)
    {
        struct node *p_temp=(*p_list)->p_head;
        while(p_temp!=NULL)
        {
            struct node *p_del=p_temp;
            p_temp=p_temp->p_next;
            free(p_del);
        }
        free(*p_list); *p_list=NULL;
    }
}

//afficher
void print (Dlist *p_list)
{
    struct node *elem;
    elem = p_list->p_head;
    int num;
    for (num = 0 ; num < (p_list->length) ; num++)
    {
        printf("Element %d = %d\n", num, elem->data);
        elem = elem->p_next;
    }
}

//taille
void taille (Dlist *p_list)
{
    int t = 0;
    t = p_list->length;
    printf("La taille de la liste est %d\n", t);
}


Dlist *concat2 (Dlist *L1, Dlist *L2)
{
    struct node *p1 = NULL, *p2 = NULL;
    p1 = L1->p_head;
	p2 = L2->p_head;
	Dlist *L = dlist_new();
    int v = 0;
    while (p1 != NULL)
    {
    	int v = p1->data;
    	L = dlist_append(L, v);
    	p1 = p1->p_next;
    }
    
    while (p2 != NULL)
    {
    	int v = p2->data;
    	L = dlist_append(L, v);
    	p2 = p2->p_next;
    }
	return L;
}

Dlist *fusion2 (Dlist *L1, Dlist *L2)
{
	Dlist *L = dlist_new();
	struct node *p1 = L1->p_head;
	struct node *p2 = L2->p_head;
	int v = 0, w = 0;
	while(p1 != NULL)
	{
		v = p1->data;
		w = p2->data;
		L = dlist_append(L, v);
		L = dlist_append(L, w);
		p1 = p1->p_next;
		p2 = p2->p_next;
	}
	return L;
}

void *maxx(Dlist *L)
{
	struct node *p = L->p_head;
	int v = 0, m = 0;
	while (p != NULL)
	{
		v = p->data;
		if(v > m)
			m = v;
		p = p->p_next;
	}
	printf("Le max est %d\n", m);
}

