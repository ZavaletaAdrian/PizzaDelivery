#include <iostream>
#include <iostream>
#include<fstream>
#include<string>
#include <stdlib.h>
//#include "Grafo.h"
#include "include/Grafo.h"
#include <limits.h>
#include <stdio.h>

/**
NOTA: Si te aparecen el SRC y los HEADERS en el MANEJADOR DEL PROYECTO
EN LA IZQUIERDA, descomenta el "//#include "Grafo.h"" y comenta
con CTRL + SHIFT + C [Los 3 al mismo tiempo, no por separado] el "#include "include/Grafo.h"".

Al igual de los demás .cpp y .h
*/

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
