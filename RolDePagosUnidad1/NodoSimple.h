#pragma once
#include <iostream>

template <typename T>
class NodoSimple {
private:
	T valor;
	NodoSimple<T>* siguiente = nullptr;

public:
	NodoSimple(T val) {
		this->valor = val;
	}

	void setValor(T v) {
		valor = v;
	}

	T getValor() {
		return this->valor;
	}

	void setSiguiente(NodoSimple<T>* sig) {
		siguiente = sig;
	}

	NodoSimple<T>* getSiguiente() {
		return this->siguiente;
	}
};