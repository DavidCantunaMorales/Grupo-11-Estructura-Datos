#pragma once

#include <iostream>

template <typename T>
class NodoDoble {
private:
	T* valor;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;
public:

	NodoDoble(int v, NodoDoble<T>* s = NULL, NodoDoble<T>* a = NULL) {
		this->valor = v;
		this->siguiente = s;
		this->anterior = a;
	}

	NodoDoble(T* val) {
		this->valor = val;
		this->siguiente = NULL;
		this->anterior = NULL;
	}

	T* getValor() {
		return this->valor;
	}

	void setValor(T* v) {
		valor = v;
	}

	NodoDoble<T>* getSiguiente() {
		return this->siguiente;
	}

	void setSiguiente(NodoDoble<T>* newSiguiente) {
		siguiente = newSiguiente;
	}

	NodoDoble<T>* getAnterior() {
		return this->anterior;
	}

	void setAnterior(NodoDoble<T>* newAnterior) {
		anterior = newAnterior;
	}
};