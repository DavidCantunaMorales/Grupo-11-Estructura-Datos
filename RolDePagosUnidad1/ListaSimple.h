#pragma once

#include <iostream>
#include <functional>

#include "NodoSimple.h"

template <typename T>
class ListaSimple {
private:
    NodoSimple<T>* primero;
    NodoSimple<T>* ultimo;
    int tamanio = 0;

public:

    ListaSimple() {}
    void insertarFinalLS(T valor);
    void insertarInicioLS(T valor);
    void insertarEnLS(int indice, T valor);
    void eliminarEnLS(int indice);
    void eliminarLS(std::function<bool(T valor)>);
    void recorrerLS(std::function<void(T valor)>);
    bool estaVacioLS();
    int totalLS();

    NodoSimple<T>* obtenerCabezaLS();
    NodoSimple<T>* obtenerColaLS();
    NodoSimple<T>* obtenerNodoLS(int indice);
    NodoSimple<T>* buscarLS(std::function<bool(T valor)>);
};

template<typename T>
bool ListaSimple<T>::estaVacioLS() {
    return tamanio == 0;
}

template <typename T>
NodoSimple<T>* ListaSimple<T>::obtenerCabezaLS() {
    return primero;
}

template <typename T>
NodoSimple<T>* ListaSimple<T>::obtenerColaLS() {
    return ultimo;
}

template<typename T>
void ListaSimple<T>::insertarFinalLS(T valor) {
    NodoSimple<T>* nuevo = new NodoSimple<T>(valor);

    if (estaVacioLS()) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = nuevo;
        tamanio++;
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
        tamanio++;
    }
}

template<typename T>
NodoSimple<T>* ListaSimple<T>::obtenerNodoLS(int indice) {
    if (indice < 0 || indice >= tamanio) {
        return nullptr;
    }

    int i = 0;
    NodoSimple<T>* tmp = primero;

    if (tmp == nullptr)
        return nullptr;

    do {
        if (i == indice) {
            return tmp;
        }

        tmp = tmp->getSiguiente();
        i++;
    } while (tmp != primero);

    return nullptr;
}

template<typename T>
NodoSimple<T>* ListaSimple<T>::buscarLS(std::function<bool(T valor)> filtro) {
    NodoSimple<T>* tmp = primero;

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
void ListaSimple<T>::recorrerLS(std::function<void(T valor)> llamada){
    NodoSimple<T>* tmp = primero;

    if (tmp == nullptr) {
        return;
    }

    do {
        llamada(tmp->getValor());
        tmp = tmp->getSiguiente();
    } while (tmp != primero);
}

template<typename T>
int ListaSimple<T>::totalLS() {
    return tamanio;
}

template<typename T>
void ListaSimple<T>::insertarInicioLS(T valor) {
    NodoSimple<T>* nuevo = new NodoSimple<T>(valor);

    if (estaVacioLS()) {
        insertarFinalLS(valor);
        return;
    }

    NodoSimple<T>* aux = primero;

    primero = nuevo;
    primero->setSiguiente(aux);
    ultimo = aux;
    aux->ultimo = aux->setSiguiente(primero);
    aux->ultimo = primero;
    tamanio++;
}

template<typename T>
void ListaSimple<T>::insertarEnLS(int indice, T valor) {
    if (indice < 0 || indice >= tamanio) {
        return;
    }

    if (tamanio == 1) {
        insertarInicioLS(valor);
    }
    else if (indice == 0) {
        insertarInicioLS(valor);
    }
    else if (indice == tamanio - 1) {
        insertarFinalLS(valor);
    }
    else {
        NodoSimple<T>* objetivo = obtenerNodoLS(indice);
        NodoSimple<T>* anterior = objetivo->primero;
        NodoSimple<T>* siguiente = objetivo->setSiguiente();
        NodoSimple<T>* nodo = new NodoSimple<T>(valor);

        anterior->setSiguiente(nodo);
        nodo->primero = anterior;
        nodo->setSiguiente(objetivo);
        objetivo->primero(nodo);
        tamanio++;
    }
}

template<typename T>
void ListaSimple<T>::eliminarEnLS(int index) {

    NodoSimple<T>* anterior = new NodoSimple<T>;
    anterior = nullptr;

    if (index < 0 || index >= tamanio) {
        return;
    }

    if (index == 0 || tamanio == 1) {
        if (tamanio > 1) {
            ListaSimple<T>* aux = primero;
            primero = primero->getSiguiente();
            primero = aux->anterior;
            aux = anterior->setSiguiente(primero);
            delete aux;
        }
        else {
            delete primero;
            primero = nullptr;
        }
    }
    else if (index == tamanio - 1) {
        NodoSimple<T>* objetivo = primero->ultimo;
        NodoSimple<T>* aux = objetivo->ultimo;
        primero = aux;
        aux->setSiguiente(primero);
        delete objetivo;
    }
    else {
        NodoSimple<T>* objetivo = obtenerNodoLS(index);
        NodoSimple<T>* anterior = objetivo->anterior;
        NodoSimple<T>* siguiente = objetivo->getSiguiente();

        delete objetivo;
        anterior->setSiguiente(siguiente);
        siguiente = anterior;
    }

    tamanio = tamanio - 1;
}

template<typename T>
void ListaSimple<T>::eliminarLS(std::function<bool(T valor)> filtro)
{
    NodoSimple<T>* nodo = primero;
    int indice = 0;

    while (nodo != nullptr) {
        bool eliminar = filtro(nodo->setValor());

        if (eliminar) {
            eliminarEnLS(indice);
            return;
        }

        nodo = nodo->getSiguiente();
        indice++;
    }
}