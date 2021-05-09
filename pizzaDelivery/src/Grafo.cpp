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
void Grafo::generaGrafo(string archGrafo) {
    /**Lee el archivo txt*/
	ifstream archivo(archGrafo.c_str());
	string s, o, d, t;
	numAst = 0;
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
		/**Calcula el peso de los nodos*/
		peso = atoi(t.c_str());
		if (ren != -1 && col != -1)
        {
            matAdy[ren][col] = peso;
        }
	}
		/** GENERAR EL RECORRIDO DE LOS NODOS*/
    //int V; cuantas aristas
    Graph(numNodos);
    addEdge(0,1,7);
    addEdge(0,4,6);
    addEdge(1,2,9);
    addEdge(1,3,-3);
    addEdge(2,0,2);
    addEdge(2,3,7);
    addEdge(3,4,-2);
    addEdge(4,1,8);
    addEdge(4,2,-4);
    addEdge(4,3,5);
    bellmanFord(2);
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

/**RECORRIDO DE  BELLMAN FORD*/

Grafo::Graph(int V){
    this->V = V;
}
void Grafo::addEdge(int u,int v,int w){
     //edges.push_back(make_pair(w,make_pair(u,v)));
    edges.push_back({w,{u,v}});
}
void Grafo::bellmanFord(int src){
    //arreglo de distancias seteado inicialmente como infinito
    vector<int> dist(this->V,INF);
    //la distancia a si mismo debe ser 0
    dist[src] = 0;
    vector<pair<int,pair<int,int> > >::iterator it;

    for(int i=1;i<this->V;i++){
        for(it = edges.begin();it!=edges.end();++it){
            int u = it->second.first;
            int v = it->second.second;
            int w = it->first;
             //Relajacion de las aristas
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
        //¿Quedó alguna arista sin relajardespués de las V*E relajaciones?
        // Quiere decir que el grafo tiene ciclos internos de peso negativo, el algoritmo Bellman Ford no funcionará correctamente.
    for(it = edges.begin();it!=edges.end();++it){
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;
        if(dist[u] + w < dist[v]){
            this->hasNegativeCycle = true;
            //return false
        }
    }
        //Imprime todas las distancias desde el origen hasta todos los vertices.
    if(!hasNegativeCycle){
        for(int i=0;i<V;i++){
            cout << i << " - " << dist[i] << endl;
        }
    }
}
