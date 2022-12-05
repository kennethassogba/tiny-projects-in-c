#include <stdio.h>
#include <stdlib.h>

struct graph
{
	int ordre;
	int mat[256][256];
};
typedef struct graph *graph;

graph graph_new (int ordre);
void matrice (graph g, int nba);
void graph_print (graph g);
int graph_arc(graph g, int i, int j);

int main(int argc, char *argv[]) 
{
	graph g = graph_new (5);
	int n = 0;
	matrice (g, 6);
	graph_print (g);
	printf("\n");
	n = graph_arc(g, 1, 5);
	printf("\n");
	n = graph_arc(g, 3, 5);
	printf("\n");
	n = graph_arc(g, 100, 5);
	
	return 0;
}


graph graph_new (int ordre)
{
	graph g = malloc(sizeof *g);
	if(g != NULL)
	{
		int i = 0, j = 0;
		for(i = 0; i < 256; i++)
		{
			for(j = 0; j < 256; j++)
				g->mat[i][j] = 0;
		}
		g->ordre = ordre;
		return g;
	}
	else
		return;
}

void matrice (graph g, int nba)
{
	int i = 0, x = 0, y = 0, a = 0, b = 0;
	while(i < nba)
	{
	printf("Entrez les sommets\n");
	scanf ("%d", &a);
	scanf ("%d", &b);
	g->mat[a-1][b-1] = 1;
	i++;
	}
}

void graph_print (graph g)
{
	int i = 0, j = 0;
		for(i = 0; i < g->ordre; i++)
		{
			printf(" S%d ", i+1);
			for(j = 0; j < g->ordre; j++)
				printf(" %d ", g->mat[i][j]);
			printf("\n");
		}
}

int graph_arc(graph g, int i, int j)
{
	int b = g->ordre;
	if(i <= b && j <= b)
	{
		int a = g->mat[i-1][j-1];
		if (a)
			printf ("Il existe un arc menant de %d a %d\n", i, j);
		else
			printf("Non, il n'existe pas d'arc menant de %d a %d\n", i, j);
		return a;
	}
	else
		printf("FAUX\n");
}

void graph_arc_set (graph g, int i, int j, int k)
{
	
}

