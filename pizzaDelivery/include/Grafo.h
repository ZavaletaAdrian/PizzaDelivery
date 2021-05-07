#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"

class Grafo
{
	Nodo *lista;
	int **matAdy;
	int numNodos;
public:
	Grafo(char *nomArch);
	void muestraGrafo();
	void generaListaNodos(char *nomArch);
	void generaGrafo(string nomArch);
	void muestraListaNodos();
	int buscaPosicion(string calle);
};

#endif // GRAFO_H
