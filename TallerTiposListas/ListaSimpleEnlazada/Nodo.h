#pragma once
#include <iostream>

class Nodo {
private:
	int valor;
	Nodo* siguiente;

public:
	Nodo(int v, Nodo* s = NULL) {
		this->valor = v;
		this->siguiente = s;
	}

	void setSiguiente(Nodo* sig) { 
		siguiente = sig; 
	}
	
	Nodo* getSiguiente() { 
		return this->siguiente; 
	}
	
	void setValor(int v) {
		valor = v;
	}

	int getValor() { 
		return this->valor; 
	}

	friend class Lista;
};