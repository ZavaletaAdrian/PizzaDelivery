#include <iostream>
#include <iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
#include "Grafo.h"
using namespace std;

int main()
{
    Grafo *g;
	g = new Grafo("grafo.txt");
	g->generaGrafo("grafo.txt");
	g->muestraListaNodos();
	g->muestraGrafo();
	cout << endl;
}
