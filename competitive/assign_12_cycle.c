#include<stdio.h>
#include <stdlib.h>

typedef struct {
   unsigned int first;
   unsigned int second;
} edge;

static int cyclic_recursive(const edge *edges,int n,int *visited,int order,int vertex,int predecessor)
{
    int i;
    int cycle_found = 0;
    visited[vertex] = 1;
    for (i = 0; i < n && !cycle_found; i++) {
        if (edges[i].first == vertex || edges[i].second == vertex) {

            const unsigned int neighbour = edges[i].first == vertex ?edges[i].second : edges[i].first;
            if (visited[neighbour] == 0)
            {
                cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
            }
            else if (neighbour != predecessor)
            {
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}

unsigned int cyclic(const edge *edges, int n,int order)
{
    int *visited = calloc(order, sizeof(int));
    int cycle_found;
    if (visited == NULL)
    {
        return 0;
    }
    cycle_found  = cyclic_recursive(edges, n, visited, order, 0, 0);
    free(visited);
    return cycle_found;
}

int main()
{
    const int order,n;
    edge *edges;
    unsigned int c;
    printf("Enter the number of vertices ");
    scanf("%d",&order);
    printf("Enter the number of edges ");
    scanf("%d",&n);

    edges = malloc(n * sizeof(edge));
    if (edges == NULL)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the edge %d elements ",i+1);
        scanf("%d %d",&edges[i].first,&edges[i].second);
    }

    c = cyclic(edges, n, order);
    if(c==1)
        printf("\nGraph is cyclic");
    else
        printf("\nGraph is acyclic");
    return 0;
}
