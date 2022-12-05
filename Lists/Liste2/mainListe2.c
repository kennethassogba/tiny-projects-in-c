#include <stdio.h>
#include <stdlib.h>

//definition
struct node
{
    int data;   //donn�e associ�e � l��l�ment
    struct node *p_next;  //d�signe l��l�ment suivant
    struct node *p_prev;  //d�signe l��l�ment pr�c�dant
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	Dlist *t = NULL;
	t = dlist_new();
	//ins�rer un �l�ment apr�s un �l�ment P

	t = dlist_append(t, 30);
	t = dlist_append(t, 40);
	t = dlist_append(t, 50);
	t = dlist_prepend(t, 20);
	t = dlist_prepend(t, 10);
	print (t);
	printf("\n");
	t = dlist_remove(t, 20);
	print (t);
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
    if(p_list!=NULL)/*On v�rifie si notre liste a �t� allou�e*/
    {
        struct node *p_new=malloc(sizeof *p_new);/*Cr�ation d'un nouveau node*/
        if(p_new!=NULL)/*On v�rifie si le malloc n'a pas �chou�*/
        {
            if(p_list->p_tail==NULL)/*Cas o� notre liste est vide(pointeur vers fin de liste � NULL)*/
            {
                p_new->data=data;/*On 'enregistre' notre donn�e*/
                p_new->p_next=NULL;/*On fait pointer p_next vers NULL*/
                p_new->p_prev=NULL;/*On fait pointer p_prev vers NULL*/
                p_list->p_head=p_new;/*On fait pointer la t�te de liste vers le nouvel �l�ment*/
                p_list->p_tail=p_new;/*On fait pointer la fin de liste vers le nouvel �l�ment*/
            }
            else/*Cas o� des �l�ments sont d�j� pr�sents dans notre liste*/
            {
                p_new->data=data;/*On'enregistre'notredonn�e*/
                p_new->p_next=NULL;/*Onfaitpointerp_nextversNULL*/
                p_list->p_tail->p_next=p_new;/*On relie le dernier �l�ment de la liste vers notre nouvel �l�ment*/
                p_new->p_prev=p_list->p_tail;/*On fait pointer p_prev vers le dernier �l�ment de la liste*/
                p_list->p_tail=p_new;/*On fait pointer la fin de liste vers notre nouvel  �l�ment*/
            }
            p_list->length++;/*Incr�mentation de la taille de la liste*/
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

//Suppression d�un �l�ment de la liste selon sa valeur
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

//Lib�rer une liste
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


Dlist *conc (Dlist *L1, Dlist *L2)
{
    Dlist *L = dlist_new();
    while ()
    return L;
}


