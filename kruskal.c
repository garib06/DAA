#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define INF 9999



typedef struct
{
   int u, v, w;
} Edge;

int parent[MAX];
int find(int i)
{
   while (parent[i] != i)
      i = parent[i];
   return i;
}
void union1(int i, int j)
{
   int a = find(i);
   int b = find(j);
   parent[a] = b;
}
void kruskal(Edge edges[], int n)
{
   int i, j, u, v;
   Edge temp;
   for (i = 0; i < n; i++)
      parent[i] = i;
   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - 1 - i; j++)
      {
         if (edges[j].w > edges[j + 1].w)
         {
            temp = edges[j];
            edges[j] = edges[j + 1];
            edges[j + 1] = temp;
         }
      }
   }
   printf("Edges of MST are:\n");
   for (i = 0; i < n; i++)
   {
      u = find(edges[i].u);
      v = find(edges[i].v);
      if (u != v)
      {
         printf("%d -> %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
         union1(u, v);
      }
   }
}

int main()
{
   int n, e;
   printf("Enter the number of vertices and edges:\n");
   scanf("%d %d", &n, &e);
   Edge edges[e];
   printf("Enter the edges (u, v, w):\n");
   for (int i = 0; i < e; i++)
   {
      scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
   }
   kruskal(edges, e);
   return 0;
}