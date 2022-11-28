#pragma once
#include <iostream>
#include "Nodo.h"

class Lista {
private:
	Nodo* primero;
	Nodo* actual;
    int dimLista = 0;

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

    Nodo* getActual() {
        return actual;
    }

    void setActual(Nodo* act) {
        actual = act;
    }
    int getDimLista() {
        return dimLista;
    }

    void setDimLista(int dim) {
        dimLista = dim;
    }

    Lista();

    Nodo* obtenerNodo(int indice);

    void insertar(int val);

    void insertarEn(int indice, int val);

    void eliminar(int indice);

    void buscar(int val);

    void mostrar();

    void mostrarRecursivo(Nodo* valor, int indice);

    int sumaTotal();

    int sumarPares();

    Lista guardarLista(Lista);

    int maximoComunDivisor(Lista);

    int mcd(int, int);

    int minimoComunMultiplo(Lista);

    Lista calcularUnidades(Lista);

    int sumaNumeros(int a);

    int dimensionNumero(int numero);

    int sumaRecursiva(int a);

    int sumaDos(int a);
};