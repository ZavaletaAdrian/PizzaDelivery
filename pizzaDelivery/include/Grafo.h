#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

#define V 9
class Grafo
{
    int dis[9];
	Nodo *lista;
	int **matAdy;
	int numNodos;
//	int numAst; //Para las aristas
//	int V;
        //lista de aristas, con formato <peso,<origen,destino>>
        vector<pair<int,pair<int,int>>> edges;
        bool hasNegativeCycle = false;
public:
	Grafo(char *nomArch);
	void muestraGrafo();
	void generaListaNodos(char *nomArch);
	void generaGrafo(string nomArch);
	void muestraListaNodos();
	int buscaPosicion(string calle);
//	int BellmanFordRecorr(Nodo *lista,int numNodos, int numAst);
//    Graph(int V);
//    void addEdge(int u,int v,int w);
//    void bellmanFord(int src);
    void ingresarNodos(int **matAdy);
    void recorrido(int nodosRecor[], int **matAdy);
    void dijkstra(int **matAdy, int src);
    int minDistance(int dist[], bool sptSet[]);
    void printSolution(int dist[]);

};

#endif // GRAFO_H
