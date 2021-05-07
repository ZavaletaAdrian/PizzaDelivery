#include "Grafo.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Nodo.h"
#include "Cola.h"

using namespace std;

Grafo::Grafo(char *archGrafo)
{
    string cadena;
	ifstream archivo("grafo.txt");
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo, intenta más tarde" << endl;
		exit(1);
	}
	getline(archivo, cadena);
	numNodos = atoi(cadena.c_str());
	cout << numNodos << endl;
	lista = new Nodo[numNodos];
	matAdy = new int*[numNodos];
	for (int i = 0; i < numNodos; i++) {
		matAdy[i] = new int[numNodos];
		for (int j = 0; j < numNodos; j++) {
			matAdy[i][j] = 0;
		}
	}
	generaListaNodos(archGrafo);
	generaGrafo(archGrafo);
}

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

void Grafo::generaGrafo(string archGrafo) {
	ifstream archivo(archGrafo.c_str());
	string s, o, d, t;
	int numAst = 0;
	int peso, ren, col;
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
			matAdy[ren][col] = peso;
	}
}

void Grafo::muestraListaNodos() {
	for (int i = 0; i < numNodos; i++)
		cout << lista[i].getInfo() << endl;
}

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

int Grafo::buscaPosicion(string calle) {
	for (int i = 0; i < numNodos; ++i) {
		if (lista[i].getInfo() == calle) {
			return i;
		}
	}
	return -1;
}
