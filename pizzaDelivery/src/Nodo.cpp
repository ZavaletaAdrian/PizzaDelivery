//#include "Nodo.h"
#include "../include/Nodo.h"

Nodo::Nodo(string d){
}

Nodo::Nodo(){
	info = "";
	recorrido = false;
}

string Nodo::getInfo(){
	return info;

}

void Nodo::setInfo(string d){
	info = d;
	recorrido = true;
}

void Nodo::setRecorrido(bool r){
	recorrido = r;
}

bool Nodo::yaRecorrido(){
	return recorrido;
}

Nodo::~Nodo(){
}

