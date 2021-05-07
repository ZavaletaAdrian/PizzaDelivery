#ifndef NODO_H
#define NODO_H


#include <string>
#include<iostream>

using namespace std;

class Nodo
{
	string info;
	bool recorrido;
public:
	Nodo();
	Nodo(string d);
	void setInfo(string d);
	string getInfo();
	bool yaRecorrido();
	void setRecorrido(bool r);
	~Nodo();
};

#endif // NODO_H

