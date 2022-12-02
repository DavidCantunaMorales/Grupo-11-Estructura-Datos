#pragma once

template <typename T>
class NodoDoble {

private:
	T valor;
	NodoDoble<T>* siguiente = nullptr;
	NodoDoble<T>* anterior = nullptr;

public:
	NodoDoble(T valor) {
		this->valor = valor;
	}

	T getValor() {
		return valor;
	}

	void setValor(T valor) {
		this->valor = valor;
	}

	NodoDoble<T>* getSiguiente() {
		return siguiente;
	}

	void setSiguiente(NodoDoble<T>* siguiente) {
		this->siguiente = siguiente;
	}

	NodoDoble<T>* getAnterior() {
		return anterior;
	}

	void setAnterior(NodoDoble<T>* anterior) {
		this->anterior = anterior;
	}
};
