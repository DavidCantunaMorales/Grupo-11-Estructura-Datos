// Archivo de cabecera NodoDoble.h
#pragma once

// Clase NodoDoble
class NodoDoble
{
    // Atributos de la clase NodoDoble
private:
    int dato;
    NodoDoble *siguiente;
    NodoDoble *anterior;

    // Métodos de la clase NodoDoble
public:
    NodoDoble(); // Constructor por defecto de la clase NodoDoble.
                 // Métodos setter y getter
                 // Setters
    void setDato(int dato);
    void setSiguiente(NodoDoble *siguiente);
    void setAnterior(NodoDoble *anterior);

    // Getters
    int getDato();
    NodoDoble *getSiguiente();
    NodoDoble *getAnterior();

    // Métodos definidos por el usuario
    void generarNodoDoble(NodoDoble **nodoDoble, int dato, int &contarDatos);
    void eliminarNodoDoble(NodoDoble **nodoDoble, int posicion, int &contarDatos);
    void mostrarListaDoble(NodoDoble *nodoDoble, int contarDatos);
    void mostrarListaDoblePorLaCola(NodoDoble *nodoDoble, int contarDatos);
}; // Fin clase NodoDoble