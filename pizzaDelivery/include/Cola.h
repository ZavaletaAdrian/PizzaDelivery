#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

class Cola
{
	Nodo * cola;
	int ultimo;
	int N;
public:
	Cola(int num);
	void enque(Nodo dato);
	Nodo deque();
	bool vacia();
	void muestra();
};

#endif // COLA_H
