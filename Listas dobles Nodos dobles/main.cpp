#include <conio.h>       
#include <stdio.h>       
#include <iostream>      
#include "NodoDoble.h" 
#include "ValidarDatos.h"
using namespace std;
int main()
{
    int dato, contarDatos = 0;
    char opc = ' ';
    char opcNodoDoble = ' ';
    int posicion = 0;
    NodoDoble *nodoDoble = new NodoDoble(); 
    ValidarDatos obj;
    nodoDoble->setSiguiente(NULL);          
    nodoDoble->setAnterior(NULL);
    do
    {
        system("cls");
        cout << "***   MENU   ***" << endl
             << endl; // Impresión del menu
        cout << "1.- Generar aleatoriamente la lista doblemente enlazada " << endl;
        cout << "2.- Mostrar lista doblemente enlazada" << endl;
        cout << "3.- Eliminar nodo" << endl;
        cout << "0.- Salir" << endl
            << endl;
        cout << "Elija una opcion valida" << endl;
        opc = getch(); 
        switch (opc)
        {
        case '1': // Ingresar datos al inicio
            system("cls");
            cout << "***   GENERAR ALEATORIAMENTE LISTA DOBLEMENTE ENLAZADA   ***" << endl
                << endl;
            dato = obj.validarEntero("Ingrese cuantos nodos desea generar: ");
            // cout << "Ingrese cuantos nodos desea generar: ";
            // cin >> dato;
            nodoDoble->generarNodoDoble(&nodoDoble, dato, contarDatos);
            cout << "\nSe genero exitosamente la lista doblemente enlazada" << endl;
            system("PAUSE");

            break;
        case '2': // Mostar lista doblemente enlazada.
            system("cls");
            cout << "***   MOSTRAR LISTA DOBLEMENTE ENLAZADA   ***" << endl
                << endl;
            nodoDoble->mostrarListaDoble(nodoDoble, contarDatos);
            nodoDoble->mostrarListaDoblePorLaCola(nodoDoble,contarDatos);
            system("PAUSE");
            break;
        case '3': // Eliminar nodo
            system("cls");
            cout << "***    ELIMINAR NODO   ***" << endl
                << endl;
            nodoDoble->mostrarListaDoble(nodoDoble, contarDatos);
            do
            {
                posicion = obj.validarEntero("\nIngrese posicion: ");
                // cout << "\nIngrese posicion: ";
                // cin >> posicion;
            } while (posicion > contarDatos);

            nodoDoble->eliminarNodoDoble(&nodoDoble, posicion, contarDatos);
            cout << "\nSe elimino correctamente el nodo" << endl;
            system("PAUSE");
            break;

        case '0': 
            system("cls");
            cout << "Gracias por utilizar este programa." << endl;
            system("PAUSE");
            exit(0);
            break;
        } 

    } while (opc != '1' || opc != '2' || opc != '3' || opc != '0'); 
} 
