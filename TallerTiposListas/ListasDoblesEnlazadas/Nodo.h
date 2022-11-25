#pragma once
#pragma once
#include <iostream>
class Nodo {
private:
	int valor;
	Nodo* siguiente;
	Nodo* anterior;
public:

	Nodo(int v, Nodo* s = NULL, Nodo* a = NULL) {
		this->valor = v;
		this->siguiente = s;
		this->anterior = a;
	}

	int getValor() {
		return this->valor;
	}

	void setValor(int v) {
		valor = v;
	}

	Nodo* getSiguiente() {
		return this->siguiente;
	}

	void setSiguiente(Nodo* newSiguiente) {
		siguiente = newSiguiente;
	}

	Nodo* getAnterior() {
		return this->anterior;
	}

	void setAnterior(Nodo* newAnterior) {
		anterior = newAnterior;
	}

	friend class Lista;
};