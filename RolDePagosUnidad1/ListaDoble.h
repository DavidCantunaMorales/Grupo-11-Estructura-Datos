#pragma once

#include "NodoDoble.h"

#include <functional>
#include <iostream>


template<typename T>
class ListaDoble {
private:
    NodoDoble<T>* primero = nullptr;
    NodoDoble<T>* ultimo = nullptr;
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

    NodoDoble<T>* obtenerPrimeroLD();
    NodoDoble<T>* obtenerUltimoLD();
    NodoDoble<T>* obtenerNodoLD(int indice);
    NodoDoble<T>* buscarLD(std::function<bool(T valor)>);
};

template<typename T>
void ListaDoble<T>::insertarFinalLD(T valor) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

    if (primero == nullptr) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
        primero->setAnterior(ultimo);
        tamanio++;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
        primero->setAnterior(ultimo);
        tamanio++;
    }
}

template<typename T>
void ListaDoble<T>::insertarInicioLD(T valor) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

    if (estaVacioLD()) {
        insertarFinalLD(valor);
        return;
    }

    NodoDoble<T>* aux = primero;

    primero = nuevo;
    primero->setSiguiente(aux);
    primero->setAnterior(aux->setAnterior());
    aux->setAnterior()->setSiguiente(primero);
    aux->setAnterior(primero);
    tamanio++;
}

template<typename T>
void ListaDoble<T>::insertarEnLD(int indice, T valor) {
    if (indice < 0 || indice >= tamanio) {
        return;
    }

    if (tamanio == 1) {
        insertarInicioLD(valor);
    }
    else if (indice == 0) {
        insertarInicioLD(valor);
    }
    else if (indice == tamanio - 1) {
        insertarFinalLD(valor);
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
            NodoDoble<T>* aux = primero;
            primero = primero->getSiguiente();
            primero->setAnterior(aux->setAnterior());
            aux->setAnterior()->setSiguiente(primero);
            delete aux;
        }
        else {
            delete primero;
            primero = nullptr;
        }
    }
    else if (index == tamanio - 1) {
        NodoDoble<T>* objetivo = primero->setAnterior();
        NodoDoble<T>* aux = objetivo->setAnterior();
        primero->setAnterior(aux);
        aux->setSiguiente(primero);
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
void ListaDoble<T>::eliminarLD(std::function<bool(T valor)> filtro){
    NodoDoble<T>* tmp = primero;
    int indice = 0;

    while (tmp != nullptr) {
        bool eliminar = filtro(tmp->setValor());

        if (eliminar) {
            eliminarEnLD(indice);
            return;
        }

        tmp = tmp->getSiguiente();
        indice++;
    }
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::obtenerPrimeroLD() {
    return primero;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::obtenerUltimoLD() {
    NodoDoble<T>* cola = primero;

    if (cola == nullptr) {
        return nullptr;
    }

    while (cola->getSiguiente() != primero) {
        cola = cola->getSiguiente();
    }

    return cola;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::obtenerNodoLD(int indice) {
    int cont = 0;
    NodoDoble<T>* tmp = primero;
    while (tmp->getSiguiente() != nullptr) {
        if (cont == indice) {
            break;
        }
        cont++;
        tmp = tmp->getSiguiente();
    }
    return tmp;
}

template<typename T>
NodoDoble<T>* ListaDoble<T>::buscarLD(std::function<bool(T valor)> filtro) {
    NodoDoble<T>* tmp = primero;

    if (tmp == nullptr) {
        return nullptr;
    }

    do {
        if (filtro(tmp->getValor())) {
            return tmp;
        }

        tmp = tmp->getSiguiente();  
    } while (tmp != primero);

    return nullptr;
}

template<typename T>
void ListaDoble<T>::recorrerLD(std::function<void(T valor)> llamada){
    NodoDoble<T>* tmp = primero;

    if (tmp == nullptr) {
        return;
    }

    do {
        llamada(tmp->getValor());
        tmp = tmp->getSiguiente();
    } while (tmp != primero);
}

template<typename T>
bool ListaDoble<T>::estaVacioLD() {
    return tamanio == 0;
}

template<typename T>
int ListaDoble<T>::totalLD() {
    return tamanio;;
}