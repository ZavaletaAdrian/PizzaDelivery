//#include "Grafo.h"
#include <fstream>
#include <stdlib.h>
#include <string>
//#include "Nodo.h"
//#include "Cola.h"
#include "../include/Cola.h"
#include "../include/Nodo.h"
#include "../include/Grafo.h"
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#include <limits.h>
#include <stdio.h>

#define V 9


using namespace std;
/** Empieza el programa a leer
el archivo txt*/
Grafo::Grafo(char *archGrafo)
{
/**    Lee el archivo txt */
    string cadena;
	ifstream archivo("grafo.txt");
	/**En caso de fallar el archivo, imprime un error*/
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo, intenta más tarde" << endl;
		exit(1);
	}
	/**Lee linea por linea en el archivo*/
	getline(archivo, cadena);
	/**Convierte la cadena en int y lo guarda en la variable "numNodos"*/
	 numNodos = atoi(cadena.c_str());
	cout << numNodos << endl;
	/**Crea un arreglo con el nombre de "lista" y el tamaño de "numNodos"*/
	lista = new Nodo[numNodos];
	/**Se crea una matriz de adyascencia para comprobar la conexión entre
	los nodos*/
	matAdy = new int*[numNodos];
	for (int i = 0; i < numNodos; i++) {
		matAdy[i] = new int[numNodos];
		for (int j = 0; j < numNodos; j++) {
			matAdy[i][j] = 0;
		}
	}
	/**Se generan los grafos y la lista de Nodos*/
	generaListaNodos(archGrafo);
	generaGrafo(archGrafo);
}
//OUTPUT
/**Imprime las direcciones de entrega*/
void Grafo::generaListaNodos(char *archGrafo) {
	ifstream archivo(archGrafo);
	string l;
	getline(archivo, l);
	cout << "Lista de Entrega: " << endl;
	for (int i = 0; i < numNodos; i++) {
		getline(archivo, l);
		lista[i].setInfo(l);
	}
	archivo.close();
}
/**
    SIMBOLOGIA
    s, o, d, t = variables para construir el grafo
    peso = Peso de los nodos
    ren = Renglón de la matriz
    col = Columna de la matriz
*/
int Grafo::generaGrafo(string archGrafo) {
    /**Lee el archivo txt*/
	ifstream archivo(archGrafo.c_str());
	string s, o, d, t;
	int numAst = 0;
	int peso, ren, col;
	/**Lee linea por linea del archivo*/
	getline(archivo, s);
	for (int i = 0; i < numNodos; i++) {
		getline(archivo, s);
	}
	while (!archivo.eof()) {
		getline(archivo, s);

		int j = 0;
		o = d = t = "";
		numAst = 0;
		while (j < s.length()) {
			if (s[j] != '*') {
				t = t + s[j];
			}
			else {
				numAst++;
				if (numAst == 1)
					o = t;
				else
					d = t;
				t = "";
			}
			j++;
		}
		ren = buscaPosicion(o);
		col = buscaPosicion(d);
		peso = atoi(t.c_str());
		if (ren != -1 && col != -1)
        {
            matAdy[ren][col] = peso;
        }
	}
	return **matAdy;
		/** GENERAR EL RECORRIDO DE LOS NODOS*/
    //int V; cuantas aristas
//    Graph(numNodos);
//    addEdge(0,1,7);
//    addEdge(0,4,6);
//    addEdge(1,2,9);
//    addEdge(1,3,-3);
//    addEdge(2,0,2);
//    addEdge(2,3,7);
//    addEdge(3,4,-2);
//    addEdge(4,1,8);
//    addEdge(4,2,-4);
//    addEdge(4,3,5);
//    bellmanFord(2);
}
//OUTPUT
/**Muestra la lista de los nodos*/
void Grafo::muestraListaNodos() {
	for (int i = 0; i < numNodos; i++)
		cout << lista[i].getInfo() << endl;
}
//OUTPUT
/**Muestra la matriz de Adyacencia de los Grafos*/
void Grafo::muestraGrafo() {
	cout << "\nMatriz de Adyacencia de Grafo" << endl;
	cout << " " << endl;
	for (int i = 0; i < numNodos; i++) {
		for (int j = 0; j < numNodos; j++) {
			cout << matAdy[i][j] << "  ";
		}
		cout << endl;
	}
}

/**Busca las posiciones*/
int Grafo::buscaPosicion(string calle) {
	for (int i = 0; i < numNodos; ++i) {
		if (lista[i].getInfo() == calle) {
			return i;
		}
	}
	return -1;
}

/**RECORRIDO DE DIJSKTRA*/
void Grafo::ingresarNodos(){
    cout << "BIENVENIDO AL RECORRIDO, POR FAVOR INGRESE 4 NODOS PARA RECORRER, UNO A LA VEZ" << endl;
    int temp;
    int nodosRecor[4];
    for (int i=0;i<4;i++){
        cout <<  "INGRESE EL NODO" << endl;
        cin >> temp;
        nodosRecor[i] = temp;
    }
    cout << endl;
    recorrido(nodosRecor);
}
void Grafo::recorrido(int nodosRecor[]){
    int suma = 0;
    cout << "El recorrido a seguir es : " << nodosRecor[0] << ", " <<  nodosRecor[1] << ", " << nodosRecor[2] << ", " << nodosRecor[3] << endl;
    /*dijkstra(graph, 0);
    printSolution(dis);*/
    int nodoAct = 0;
	for (int a=0;a<4;a++){
        dijkstra(matAdy, nodoAct);
        cout << "Del nodo " << nodoAct << " al nodo " << nodosRecor[a] << " hay un peso de ";
        nodoAct = nodosRecor[a];
        int temp = nodosRecor[a];
        cout << dis[temp] << endl;
        suma = suma + dis[temp];
        cout << "el peso actual es de: " << suma << endl;
        printSolution(dis);
        cout << endl;
    }
    cout << "EL PESO DE MINUTOS TOTALES FUE DE : " << suma << endl;
    if (suma < 15){
        cout << "Cobra la pizza" << endl;
    }else{
        cout << "Es gratis la pizza" << endl;
    }

}

/**Una función que implementa el recorrido del algoritmo de Dijkstra
representado por una matriz de adyacencia*/
void Grafo::dijkstra(int **matAdy, int src)
{
	int dist[V]; /** La matriz de salida. dist[i] contendrá la
	distancia más corta desde src hasta i*/

	bool sptSet[V]; /** sptSet[i] será verdadero si el vértice i está incluido en el
	árbol del camino más corto o la distancia más corta de src a i está finalizada */

	/** Inicializa todas las distancias como INFINITO y stpSet[] como falso*/
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	/** La distancia del vértice de origen a sí mismo es siempre 0 */
	dist[src] = 0;

	/** Encontrar el camino más corto para todos los vértices */
	for (int count = 0; count < V - 1; count++) {
		/** Elige el vértice de mínima distancia del conjunto de vértices aún no procesados La variable "u" es siempre igual a src en la primera iteración.*/
		int u = minDistance(dist, sptSet);

		/** Marcar el vértice elegido como procesado */
		sptSet[u] = true;

		/** Actualiza el valor de dist de la adyacencia de vertices de el vértice elegido*/
		for (int v = 0; v < V; v++)

                /** Actualizar dist[v] sólo si no está en sptSet,
                hay una arista de "u" a "v", y el peso total de la ruta de "src" a "v"
                a través de "u" es menor que el valor actual de "dist[v]"*/
			if (!sptSet[v] && matAdy[u][v] && dist[u] != INT_MAX
				&& dist[u] + matAdy[u][v] < dist[v])
				dist[v] = dist[u] + matAdy[u][v];
	}

	/** Imprimir la matriz de distancia construida
	printSolution(dist);**/
	for (int i=0;i<9;i++){
        dis[i] = dist[i];
	}
}
int Grafo::minDistance(int dist[], bool sptSet[])
{
	/**Inicializa el valor minimo*/
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

/** Una función de utilidad para imprimir la matriz de distancia construida */
void Grafo::printSolution(int dist[])
{
	printf("Vértice \t\t Distancia desde la salida\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
