#pragma once

template <typename T>
class NodoCircular {

private:
	T valor;
	NodoCircular<T>* siguiente = nullptr;
	NodoCircular<T>* anterior = nullptr;

public:
	NodoCircular(T valor) {
		this->valor = valor;
	}

	T getValor() {
		return valor;
	}

	void setValor(T valor) {
		this->valor = valor;
	}

	NodoCircular<T>* getSiguiente() {
		return siguiente;
	}

	void setSiguiente(NodoCircular<T>* siguiente) {
		this->siguiente = siguiente;
	}

	NodoCircular<T>* getAnterior() {
		return anterior;
	}

	void setAnterior(NodoCircular<T>* anterior) {
		this->anterior = anterior;
	}
};
