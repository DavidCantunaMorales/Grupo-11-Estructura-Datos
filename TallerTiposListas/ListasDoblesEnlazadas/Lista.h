#pragma once
#include <iostream>
#include "Nodo.h"

class Lista {
private:
    Nodo* primero;
    Nodo* ultimo;

public:

    bool listaVacia() {
        return (primero == NULL);
    };

    Nodo* getPrimero() {
        return primero;
    }

    void setPrimero(Nodo* pri) {
        primero = pri;
    }

    Nodo* getUltimo() {
        return ultimo;
    }

    void setUltimo(Nodo* ult) {
        ultimo = ult;
    }

    Lista();

    Nodo* obtenerNodo(int indice);

    void insertar(int val);

    //void insertarEn(int indice, int val);

    void eliminar(int indice);

    void buscar(int val);

    void mostrar();

    int obtenerTamnioLista();

    //void mostrarRecursivo(Nodo* valor, int indice);
    //int sumaTotal();
    ///int sumarPares();
    //Lista guardarLista(Lista);

    int mcd(int, int);
    int maximoComunDivisor(Lista);

    int minimoComunMultiplo(Lista);
};