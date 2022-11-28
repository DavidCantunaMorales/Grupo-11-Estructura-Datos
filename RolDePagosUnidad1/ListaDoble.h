#pragma once

#include "NodoDoble.h"

#include <functional>
#include <iostream>

template<typename T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza = nullptr;
    int tamanio = 0;

public:

    ListaDoble() {}
    void insertarFinalLD(T valor);
    void insertarInicioLD(T valor);
    void insertarEnLD(int indice, T valor);
    void eliminarEnLD(int indice);
    void eliminarLD(std::function<bool(T valor)>);
    void recorrerLD(std::function<void(T valor)>);
    bool estaVacioLD();
    int totalLD();

    NodoDoble<T>* obtenerCabezaLD();
    NodoDoble<T>* obtenerColaLD();
    NodoDoble<T>* obtenerNodoLD(int indice);
    NodoDoble<T>* buscarLD(std::function<bool(T valor)>);
};

template<typename T>
void ListaDoble<T>::insertarFinalLD(T valor) {
    NodoDoble<T>* nodo = new NodoDoble<T>(valor);

    if (cabeza == nullptr) {
        cabeza = nodo;
        cabeza->setAnterior(cabeza);
        cabeza->setSiguiente(cabeza);
        tamanio++;
    }
    else {
        NodoDoble<T>* cola = obtenerColaLD();
        cola->setSiguiente(nodo);
        nodo->setAnterior(cola);
        nodo->setSiguiente(cabeza);
        cabeza->setAnterior(nodo);
        tamanio++;
    }
}

template<typename T>
void ListaDoble<T>::insertarInicioLD(T valor) {
    NodoDoble<T>* nodo = new NodoDoble<T>(valor);

    if (estaVacioLD()) {
        insertarFinal(valor);
        return;
    }

    NodoDoble<T>* aux = cabeza;

    cabeza = nodo;
    cabeza->setSiguiente(aux);
    cabeza->setAnterior(aux->setAnterior());
    aux->setAnterior()->setSiguiente(cabeza);
    aux->setAnterior(cabeza);
    tamanio++;
}

template<typename T>
void ListaDoble<T>::insertarEnLD(int indice, T valor) {
    if (indice < 0 || indice >= tamanio) {
        return;
    }

    if (tamanio == 1) {
        insertarInicio(valor);
    }
    else if (indice == 0) {
        insertarInicio(valor);
    }
    else if (indice == tamanio - 1) {
        insertarFinal(valor);
    }
    else {
        NodoDoble<T>* objetivo = obtenerNodoLD(indice);
        NodoDoble<T>* anterior = objetivo->setAnterior();
        NodoDoble<T>* siguiente = objetivo->setSiguiente();
        NodoDoble<T>* nodo = new NodoDoble<T>(valor);

        anterior->setSiguiente(nodo);
        nodo->setAnterior(anterior);
        nodo->setSiguiente(objetivo);
        objetivo->setAnterior(nodo);
        tamanio++;
    }
}

template<typename T>
void ListaDoble<T>::eliminarEnLD(int index) {
    if (index < 0 || index >= tamanio) {
        return;
    }

    if (index == 0 || tamanio == 1) {
        if (tamanio > 1) {
            NodoDoble<T>* aux = cabeza;
            cabeza = cabeza->getSiguiente();
            cabeza->setAnterior(aux->setAnterior());
            aux->setAnterior()->setSiguiente(cabeza);
            delete aux;
        }
        else {
            delete cabeza;
            cabeza = nullptr;
        }
    }
    else if (index == tamanio - 1) {
        NodoDoble<T>* objetivo = cabeza->setAnterior();
        NodoDoble<T>* aux = objetivo->setAnterior();
        cabeza->setAnterior(aux);
        aux->setSiguiente(cabeza);
        delete objetivo;
    }
    else {
        NodoDoble<T>* objetivo = obtenerNodoLD(index);
        NodoDoble<T>* anterior = objetivo->setAnterior();
        NodoDoble<T>* siguiente = objetivo->getSiguiente();

        delete objetivo;
        anterior->setSiguiente(siguiente);
        siguiente->setAnterior(anterior);
    }

    tamanio = tamanio - 1;
}

template<typename T>
void ListaDoble<T>::eliminarLD(std::function<bool(T valor)> filtro)
{
    NodoDoble<T>* nodo = cabeza;
    int indice = 0;

    while (nodo != nullptr) {
        bool eliminar = filtro(nodo->setValor());

        if (eliminar) {
            eliminarEnLD(indice);
            return;
        }

        nodo = nodo->getSiguiente();
        indice++;
    }
}

template <typename T>
inline NodoDoble<T>* ListaDoble<T>::obtenerCabezaLD() {
    return cabeza;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::obtenerColaLD() {
    NodoDoble<T>* cola = cabeza;

    if (cola == nullptr) {
        return nullptr;
    }

    while (cola->getSiguiente() != cabeza) {
        cola = cola->getSiguiente();
    }

    return cola;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::obtenerNodoLD(int indice) {
    if (indice < 0 || indice >= tamanio) {
        return nullptr;
    }

    int i = 0;
    NodoDoble<T>* nodo = cabeza;

    if (nodo == nullptr)
        return nullptr;

    do {
        if (i == indice) {
            return nodo;
        }

        nodo = nodo->getSiguiente();
        i++;
    } while (nodo != cabeza);

    return nullptr;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::buscarLD(std::function<bool(T valor)> filtro) {
    NodoDoble<T>* nodo = cabeza;

    if (nodo == nullptr) {
        return nullptr;
    }

    do {
        if (filtro(nodo->getValor())) {
            return nodo;
        }

        nodo = nodo->getSiguiente();
    } while (nodo != cabeza);

    return nullptr;
}

template<typename T>
void ListaDoble<T>::recorrerLD(std::function<void(T valor)> llamada){
    NodoDoble<T>* nodo = cabeza;

    if (nodo == nullptr) {
        return;
    }

    do {
        llamada(nodo->getValor());
        nodo = nodo->getSiguiente();
    } while (nodo != cabeza);
}

template<typename T>
bool ListaDoble<T>::estaVacioLD() {
    return tamanio == 0;
}

template<typename T>
int ListaDoble<T>::totalLD() {
    return tamanio;;
}