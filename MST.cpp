#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Edge {
    int s, d, w; 
};
struct subset
{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int edgeComparison(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->w > b1->w;
}
int main() {
    int V, E;
    cin>>V>>E;
    struct Edge* edge = (struct Edge*) malloc( E * sizeof( struct Edge ) );
    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        cin>>s>>d>>w;
        edge[i].s = s;
        edge[i].d = d;
        edge[i].w = w;
    }
    qsort(edge, E, sizeof(edge[0]), edgeComparison);
    struct Edge mst[V-1];
    int mstSize = 0;
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    for(int i = 0; i < E; i++) {
        struct Edge minEdge = edge[i];
        int x = find(subsets, minEdge.s-1);
        int y = find(subsets, minEdge.d-1);
        if (x != y) {
            mst[mstSize++] = minEdge;
            Union(subsets, x, y);
        }
        if(mstSize == V-1) {
            break; 
        }
    }
    int totalWeight = 0;
    for(int i = 0; i < V-1; i++) {
        totalWeight += mst[i].w;
    }
    cout<<totalWeight<<"\n";
    return 0;
}
