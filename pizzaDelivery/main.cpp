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
	printf("Con referente a la siguiente lista, escoge de que nodo a que nodo quieres ir:\nNOTA: Estas en el nodo 0\n[0]: Av_20_de_Noviembre\n[1]: Av_Luis_Pasteur\n[2]: La_Aurora\n[3]: Espiritu_Santo\n[4]: Oscar_Galicia\n[5]: Lic_Parras\n[6]: Calvario\n[7]: Orquidea\n[8]: Fray_Junipero\n\n");
	g->ingresarNodos();
	cout << endl;
}
