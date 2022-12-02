#pragma once

#include "NodoCircular.h"

#include <functional>
#include <iostream>

using namespace std;

template<typename T>
class ListaCircularDoble {
private:
    NodoCircular<T>* primero = nullptr;
    NodoCircular<T>* ultimo = nullptr;
    int tamanio = 0;

public:
    ListaCircularDoble();
    void insertarFinal(T valor);
    void insertarInicio(T valor);
    void insertarEn(int indice, T valor);
    void eliminarEn(int indice);
    void eliminar(std::function<bool(T valor)>);
    void recorrer(std::function<void(T valor)>);
    
    void imprimirListaPU();
    void imprimirListaUP();
    void buscarElemento(std::string cedula);

    bool listaVacia();
    int total();

    NodoCircular<T>* getPrimero();
    NodoCircular<T>* getUltimo();
    NodoCircular<T>* obtenerNodo(int indice);

    NodoCircular<T>* buscar(std::function<bool(T valor)>);
};


template<typename T>
ListaCircularDoble<T>::ListaCircularDoble() {
    this->primero = NULL;
    this->ultimo = NULL;
}

// primero = null         ultimo = null          nuevo = 67        67,23,8,12
// primero = 67           ultimo = 67            nuevo = 23        67,23,8,12
// Lista Circular Doble  =  67 
template<typename T>
void ListaCircularDoble<T>::insertarFinal(T valor){
    NodoCircular<T>* nuevo = new NodoCircular<T>(valor);
    if (listaVacia()) {
        primero = nuevo; // primero = 67
        ultimo = nuevo;  // ultirmo = 67
        primero->setSiguiente(primero);  // 67 -> (primero) = 67 -> (67)
        primero->setAnterior(ultimo);	 //  ultimo <- 67 -> primero =  (67) <- 67 -> (67)  
        tamanio++;
    }
    else {
        ultimo->setSiguiente(nuevo);  // (67) <- 67 -> (23)
        nuevo->setAnterior(ultimo);   // (67) <- 67 -> <- (23)
        nuevo->setSiguiente(primero); // (67) <- 67 -> <- (23) -> (67) 
        ultimo = nuevo;             // ultimo = 23
        primero->setAnterior(ultimo); // (23) <- 67 -> <- 23 -> (67)     
        tamanio++;
    }
}

template<typename T>
void ListaCircularDoble<T>::insertarInicio(T valor){
    NodoCircular<T>* nuevo = new NodoCircular<T>(valor);

    if (listaVacia()) {
        insertarFinal(valor);
        return;
    }

    NodoCircular<T>* aux = primero;

    primero = nuevo;
    primero->setSiguiente(aux);
    primero->setAnterior(aux->setAnterior());
    aux->setAnterior()->setSiguiente(primero);
    aux->setAnterior(primero);
    tamanio++;
}

template<typename T>
void ListaCircularDoble<T>::insertarEn(int indice, T valor){
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
        NodoCircular<T>* objetivo = obtenerNodo(indice);
        NodoCircular<T>* anterior = objetivo->setAnterior();
        NodoCircular<T>* siguiente = objetivo->setSiguiente();
        NodoCircular<T>* nodo = new NodoCircular<T>(valor);

        anterior->setSiguiente(nodo);
        nodo->setAnterior(anterior);
        nodo->setSiguiente(objetivo);
        objetivo->setAnterior(nodo);
        tamanio++;
    }
}

template<typename T>
void ListaCircularDoble<T>::eliminarEn(int index){
    if (index < 0 || index >= tamanio) {
        return;
    }
        
    if (index == 0 || tamanio == 1) {
        if (tamanio > 1) {
            NodoCircular<T>* aux = primero;
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
        NodoCircular<T>* objetivo = primero->setAnterior();
        NodoCircular<T>* aux = objetivo->setAnterior();
        primero->setAnterior(aux);
        aux->setSiguiente(primero);
        delete objetivo;
    }
    else {
        NodoCircular<T>* objetivo = obtenerNodo(index);
        NodoCircular<T>* anterior = objetivo->setAnterior();
        NodoCircular<T>* siguiente = objetivo->getSiguiente();

        delete objetivo;
        anterior->setSiguiente(siguiente);
        siguiente->setAnterior(anterior);
    }

    tamanio = tamanio - 1;
}

template<typename T>
void ListaCircularDoble<T>::eliminar(std::function<bool(T valor)> filtro)
{
    NodoCircular<T>* nodo = primero;
    int indice = 0;

    while (nodo != nullptr) {
        bool eliminar = filtro(nodo->setValor());

        if (eliminar) {
            eliminarEn(indice);
            return;
        }

        nodo = nodo->getSiguiente();
        indice++;
    }
}

template <typename T>
NodoCircular<T>* ListaCircularDoble<T>::getPrimero() {
    return primero;
}

template<typename T>
NodoCircular<T>* ListaCircularDoble<T>::getUltimo(){
    NodoCircular<T>* cola = primero;

    if (cola == nullptr) {
        return nullptr;
    }

    while (cola->getSiguiente() != primero) {
        cola = cola->getSiguiente();
    }

    return cola;
}

template<typename T>
NodoCircular<T>* ListaCircularDoble<T>::obtenerNodo(int indice){
    if (indice < 0 || indice >= tamanio) {
        return nullptr;
    }

    int cont = 0;
    NodoCircular<T>* tmp = primero;
        
    if (tmp == nullptr)
        return nullptr;

    do {
        if (cont == indice) {
            return tmp;
        }

        tmp = tmp->getSiguiente();
        cont++;
    } while (tmp != primero);
    return nullptr;
}

template<typename T>
NodoCircular<T>* ListaCircularDoble<T>::buscar(std::function<bool(T valor)> filtro){
    NodoCircular<T>* nodo = primero;

    if (nodo == nullptr) {
        return nullptr;
    }

    do {
        if (filtro(nodo->getValor())) {
            return nodo;
        }

        nodo = nodo->getSiguiente();
    } while (nodo != primero);

    return nullptr;
}

template<typename T>
void ListaCircularDoble<T>::recorrer(std::function<void(T valor)> llamada)
{
    NodoCircular<T>* nodo = primero;

    if (nodo == nullptr) {
        return;
    }

    do {
        llamada(nodo->getValor());
        nodo = nodo->getSiguiente();
    } while (nodo != primero);
}

template<typename T>
void ListaCircularDoble<T>::imprimirListaPU(){
    NodoCircular<T>* actual =  new NodoCircular<T>;
    actual = primero;
    if (primero != NULL) {
        do {
            std::cout << actual->getValor() << " -> ";
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void ListaCircularDoble<T>::imprimirListaUP(){
    NodoCircular<T>* actual = new NodoCircular<T>;
    actual = ultimo;
    if (primero != NULL) {
        do {
            std::cout << actual->getValor() << " -> ";
            actual = actual->getAnterior();
        } while (actual != ultimo);
    }
    else {
        cout << "La lista se encuentra vacia" << endl;
    }
}

template<typename T>
void ListaCircularDoble<T>::buscarElemento(std::string cedula){
    NodoCircular<T>* actual = new NodoCircular<T>;
    actual = primero;
    bool encontrado = 0;
    if (primero != NULL) {
        do {
            if (actual->getValor()->getCedula() == cedula) {
                encontrado = true;
                actual->getValor()->imprimirDatos();
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            std::cout << "El numero de cedula no se encuentra registrado" << std::endl;
        }
    }
    else {
        std::cout << "La lista esta vacia" << std::endl;
    }
}

template<typename T>
bool ListaCircularDoble<T>::listaVacia(){
    return (primero == NULL);
}

template<typename T>
int ListaCircularDoble<T>::total(){
    return tamanio;
}