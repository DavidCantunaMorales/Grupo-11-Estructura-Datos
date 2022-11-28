#include "Lista.h"

Lista::Lista(){
	this->primero = NULL;
	this->ultimo = NULL;
}

Nodo* Lista::obtenerNodo(int indice){
    int cont = 0;
    Nodo* tmp = primero;
    while (tmp->getSiguiente() != nullptr) {
        if (cont == indice) {
            break;
        }
        cont++;
        tmp = tmp->getSiguiente();
    }
    return tmp;
}

void Lista::insertar(int val){
    Nodo* nuevo = new Nodo(val);
	if (listaVacia()) {
		primero = nuevo;
		primero->setSiguiente(primero);
		ultimo = primero;
		primero->setAnterior(ultimo);
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setSiguiente(primero);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		primero->setAnterior(ultimo);
	}
}

void Lista::eliminar(int indice){


}

void Lista::buscar(int val){
	Nodo* tmp = primero;
	bool encontrado = false;

	if (primero != NULL) {
		do {
			if (tmp->valor == val) {
				std::cout << "Nodo Encontrado" << std::endl;
				std::cout << tmp->getValor() << std::endl;
				encontrado = true;
			}
			tmp = tmp->getSiguiente();
		} while (tmp != primero && encontrado != true);
		if (!encontrado) {
			std::cout << "Nodo no encontrado" << std::endl;
		}
	}
	else {
		std::cout << "La lista esta vacia" << std::endl;
	}

}

void Lista::mostrar(){
	Nodo* tmp = primero;

	if (primero != NULL) {
		do {
			std::cout << tmp->getValor() << " -> ";
			tmp = tmp->getSiguiente();
		} while (tmp != primero);
	}
	else {
		std::cout << "La lista esta vacia" << std::endl;
	}

}

int Lista::obtenerTamnioLista(){
	int dimList = 0;
	Nodo* actual = primero;
	if (primero != NULL) {
		do {
			dimList++;
			actual = actual->getSiguiente();
		} while (actual != primero);
	}
	else {
		return 0;
	}
	return dimList;
}


int Lista::mcd(int a, int b) {
	if (a == 0)
		return b;
	return mcd(b % a, a);
}

int Lista::minimoComunMultiplo(Lista list1) {
	int resultado = list1.obtenerNodo(0)->getValor();
	Nodo* indice;
	for (int i = 0; i < list1.obtenerTamnioLista(); i++) {
		indice = list1.obtenerNodo(i);
		resultado = (indice->getValor() * resultado) / mcd(indice->getValor(), resultado);
	}
	return resultado;
}

int Lista::maximoComunDivisor(Lista list1) {
	int resultado = list1.obtenerNodo(0)->getValor();
	Nodo* indice;
	for (int i = 0; i < list1.obtenerTamnioLista(); i++) {
		indice = list1.obtenerNodo(i);
		resultado = mcd(indice->getValor(), resultado);
		if (resultado == 1) {
			return 1;
		}
	}
	return resultado;
}

