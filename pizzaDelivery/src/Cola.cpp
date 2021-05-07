#include "Cola.h"
#include <iostream>
#include "Nodo.h"
#include <stdlib.h>
#include "Grafo.h"

using namespace std;

Cola::Cola(int num)
{
	cola = new Nodo[num];
	ultimo = -1;
	N = num;
}

void Cola::enque(Nodo n) {
	if (-1 <= ultimo && ultimo < N) {
		ultimo++;
		cola[ultimo] = n;
	}
	else {
		cout << "COLA LLENA" << endl;
		ultimo--;
	}
}


Nodo Cola::deque() {
	Nodo valor;
	if (ultimo >= 0) {
		valor = cola[0];
		for (int i = 0; i < ultimo; i++)
			cola[i] = cola[i + 1];
		ultimo--;
	}
	return valor;
}

bool Cola::vacia() {
	return ultimo == -1;
}


void Cola::muestra() {
	for (int i = 0; i <= ultimo; ++i) cout << "Cola[" << i << "] = " << cola[i].getInfo() << endl;
}
