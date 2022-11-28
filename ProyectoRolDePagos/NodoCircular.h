#pragma once

#include <iostream>

template <typename T>
class NodoCircular {
private:
	T* valor;
	NodoCircular<T>* siguiente;
	NodoCircular<T>* anterior;

public:
	NodoCircular(T* val) {
		this->valor = val;
		this->siguiente = NULL;
		this->anterior = NULL;
	}

	T* getValor() {
		return valor;
	}

	void setValor(T* val) {
		this->valor = val;
	}

	NodoCircular<T>* getSiguiente() {
		return siguiente;
	}

	void setSiguiente(NodoCircular<T>* sig) {
		this->siguiente = sig;
	}

	NodoCircular<T>* getAnterior() {
		return anterior;
	}

	void setAnterior(NodoCircular<T>* ant) {
		this->anterior = ant;
	}
};