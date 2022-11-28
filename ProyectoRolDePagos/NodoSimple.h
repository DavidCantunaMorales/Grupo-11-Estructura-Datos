#pragma once
#include <iostream>

template <typename T>
class NodoSimple {
private:
	T* valor;
	NodoSimple<T>* siguiente;

public:
	NodoSimple(T v, NodoSimple<T>* s = NULL) {
		this->valor = v;
		this->siguiente = s;
	}

	NodoSimple(T* val) {
		this->valor = val;
		this->siguiente = NULL;
	}

	void setSiguiente(NodoSimple<T>* sig) {
		siguiente = sig;
	}

	NodoSimple<T>* getSiguiente() {
		return this->siguiente;
	}

	void setValor(T* v) {
		valor = v;
	}

	T* getValor() {
		return this->valor;
	}
};