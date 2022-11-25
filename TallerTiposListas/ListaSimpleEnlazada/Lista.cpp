#include <iostream>
#include "Lista.h"

Lista::Lista() {
    this->primero = NULL;
    this->actual = NULL;
}

void Lista::insertar(int val){
    Nodo* nuevo = new Nodo(val);
    if (Lista::listaVacia()){
        primero = nuevo;
    }
    else{
        actual->setSiguiente(nuevo);
    }
    actual = nuevo;
    dimLista++;
}


void Lista::mostrar(){
    Nodo* tmp = primero;
    int indice = 0;
    mostrarRecursivo(tmp, indice);

}

void Lista::mostrarRecursivo(Nodo* valor, int indice) {
    std::cout << "Indice: " << indice++ << " Valor: " << valor->getValor() << std::endl;
    if (indice < dimLista)
        mostrarRecursivo(valor->getSiguiente(), indice++);
}

void Lista::eliminar(int indice){
    //elimina el primero
    if (indice == 0) {
        primero = primero->getSiguiente();
        //elimina el ultimo
    }
    else if (indice == dimLista) {
        Nodo* penultimo = obtenerNodo(indice - 2);
        penultimo->setSiguiente(nullptr);
        //elimina entre el primero y el ultimo
    }
    else {
        Nodo* actual = obtenerNodo(indice - 1);
        Nodo* tmp = obtenerNodo(indice + 1);
        actual->setSiguiente(tmp);
    }
    dimLista--;
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

Nodo* Lista::obtenerNodo(int indice){
    int cont = 0;
    Nodo* tmp = primero;
    while (tmp->getSiguiente() != nullptr){
        if (cont == indice){
            break;
        }
        cont++;
        tmp = tmp->getSiguiente();
    }
    return tmp;
}

void Lista::insertarEn(int indice, int val){
    Nodo* nuevo = new Nodo(val);
    if (indice == 0) {
        Nodo* tmp = primero;
        primero = nuevo;
        primero->setSiguiente(tmp);
    }
    else {
        Nodo* anterior = obtenerNodo(indice - 1);
        Nodo* tmp = anterior->getSiguiente();
        anterior->setSiguiente(nuevo);
        anterior = anterior->getSiguiente();
        anterior->setSiguiente(tmp);
    }
    dimLista++;

}

int Lista::sumaTotal() {
    int suma = 0;
    Nodo* tmp = primero;
    do {
        suma += tmp->getValor();
        tmp = tmp->getSiguiente();
    } while (tmp->getSiguiente() != nullptr);
    suma += tmp->getValor();
    return suma;
}

int Lista::sumarPares(){
    int suma = 0;
    Nodo* tmp = primero;
    while (tmp) {
        if (tmp->getValor() % 2 == 0) {
            suma += tmp->getValor();
        }
        tmp = tmp->getSiguiente();
    }
    return suma;
}

Lista Lista::guardarLista(Lista list1){
    Nodo* tmp = list1.getPrimero(); 
    Nodo* indice;
    Lista lst;

    for (int i = 0; i < list1.getDimLista(); i += 2) { // impares i = 0; pares i = 1;  i += 2;
        indice = list1.obtenerNodo(i);
        lst.insertar(indice->getValor());
    }

    return lst;
}

int Lista::mcd(int a, int b) {
    if (a == 0)
        return b;
    return mcd(b % a, a);
}

int Lista::minimoComunMultiplo(Lista list1){
    int resultado = list1.obtenerNodo(0)->getValor();
    Nodo* indice;
    for (int i = 0; i < list1.getDimLista(); i++) {  
        indice = list1.obtenerNodo(i);
        resultado = (indice->getValor() * resultado)/mcd(indice->getValor(), resultado);
    }
    return resultado;
}

int Lista::maximoComunDivisor(Lista list1){
    int resultado = list1.obtenerNodo(0)->getValor();
    Nodo* indice;
    for (int i = 0; i < list1.getDimLista(); i ++) { 
        indice = list1.obtenerNodo(i);
        resultado = mcd(indice->getValor(), resultado);
        if (resultado == 1){
            return 1;
        }
    }
    return resultado;
}


