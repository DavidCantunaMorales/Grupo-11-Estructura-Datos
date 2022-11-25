#include "NodoDoble.h" //Llamo al archivo de cabecera NodoDoble.h para implementar los métodos de la clase NodoDoble
#include <iostream>
using namespace std;

NodoDoble::NodoDoble() // Constructor por defecto de la clase NodoDoble.
{
	dato = 0;
	siguiente = NULL;
	anterior = NULL;
}
// Métodos setter y getter
// Setters
void NodoDoble::setDato(int dato)
{
	this->dato = dato;
}

void NodoDoble::setSiguiente(NodoDoble *siguiente)
{
	this->siguiente = siguiente;
}
void NodoDoble::setAnterior(NodoDoble *anterior)
{
	this->anterior = anterior;
}
// Getters
int NodoDoble::getDato()
{
	return dato;
}
NodoDoble *NodoDoble::getSiguiente()
{
	return siguiente;
}
NodoDoble *NodoDoble::getAnterior()
{
	return anterior;
}
// Métodos definidos por el usuario
void NodoDoble::generarNodoDoble(NodoDoble **nodoDoble, int dato, int &contarDatos) // Método en el cual se ingresan los datos a la lista doble
{
	NodoDoble *aux, *nuevo; // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiliar que apunte a la lista doble para no trabajar directamente con la lista doblemente enlazada.
	aux = *nodoDoble;		// Apunto aux a la lista doblemente enlazada
	int randomico = 0;

	for (int i = 0; i <= dato; i++)
	{
		randomico = 0;
		if (aux->getDato() == 0) // Si la lista doble esta vacia
		{
			randomico = 1 + rand() % 100;
			aux->setDato(randomico); // Envio como argumento el parámetro dato al método setDato() de la clase NodoDoble
									 // contarDatos++; //Aumento el contador de cuantos nodos  van ingresando a la lista doble.
		}
		else // Si la lista doble no esta vacia
		{
			randomico = 1 + rand() % 100;
			nuevo = new NodoDoble();		 // Reservo un espacio en memoria para el puntero nuevo que será un nuevo puntero.
			nuevo->setDato(randomico);		 // Envio como argumento el parámetro dato al método setDato() de la clase NodODoble
			nuevo->setSiguiente(*nodoDoble); // Apunto el nuevo nodo a NULL
			aux->setAnterior(nuevo);

			*nodoDoble = nuevo; // Apunto la lista doble al nuevo nodo creado,
			contarDatos++;		// Aumento el contador de cuantos nodos  van ingresando a la lista doble.
		}
	}
}

void NodoDoble::eliminarNodoDoble(NodoDoble **nodoDoble, int posicion, int &contarDatos) // Método en el cual se elimina el primer nodo de la lista doble
{
	NodoDoble *aux, *aux2; // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doblemente enlazada para no trabajar directamente con la lista doble,
						   // y declaro un aux2 para apuntar al elemento siguiente de la lista doble.
	aux = *nodoDoble;			// Apunto aux a la lista doble
	aux2 = aux->getSiguiente(); // Apunto aux2 al siguiente nodo de la lista doble.

	for (int i = 1; i <= posicion - 2; i++)
	{
		aux = aux->getSiguiente();
		aux2 = aux2->getSiguiente();
	}

	aux->setSiguiente(aux2->getSiguiente());
	aux2->setAnterior(aux);

	aux2->setSiguiente(NULL);

	contarDatos--; // Disminuyo´el número de nodos que hay en la pila
}

void NodoDoble::mostrarListaDoble(NodoDoble *nodoDoble, int contarDatos) // Método en el cual se muestra la lista doble
{
	NodoDoble *aux;	 // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
	aux = nodoDoble; // Apunto aux a pila,
	int posicion = 1;
	if (aux == NULL) // Si la lista doble esta vacia, si aux apunta a NULL.
	{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
	}
	else
	{
		while (aux->getSiguiente() != NULL) // Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
		{
			cout << "-> " << posicion << "\t" << aux->getDato() << endl;
			posicion++;
			aux = aux->getSiguiente(); // Hago que se avance al siguiente nodo de la lista doble.
		}							   // Fin while()

		cout << "\nNumero de nodos en la lista doble: " << contarDatos << endl;
	}
}
int NodoDoble::encontrarMayor(NodoDoble *nodoDoble){
		NodoDoble *tmp=nodoDoble;
		NodoDoble *aux = tmp->getSiguiente();
		int mayor{};
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
		}else{
			while(tmp){
			if(aux == nullptr){//if asigna a aux el valor de tmp cuando aux == nullptr
				aux = tmp;
			}
			if(aux->getDato() >= tmp->getDato()){
				mayor = aux->getDato();
			}
			tmp=tmp->getSiguiente();
			aux = aux->getSiguiente();	
		}
		}
		return mayor;
	}
int NodoDoble::encontrarMenor(NodoDoble *nodoDoble){
		NodoDoble *tmp=nodoDoble;
		//Nodo *aux = this->primero->siguiente;
		int menor = tmp->getDato();
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
		}else{
			while(tmp){
			if(tmp->getDato() <= menor){
				menor = tmp->getDato();
			}
			tmp=tmp->getSiguiente();
		}
		}
		return menor;
	}
int NodoDoble::minimoComunMultiplo(NodoDoble *nodoDoble){
		NodoDoble *tmp=nodoDoble;
		int mayor = tmp->encontrarMayor(nodoDoble);//asignamos el valor mayor de la lista]
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
		}else{
			while(tmp){
			if(mayor%tmp->getDato() == 0){
				tmp=tmp->getSiguiente();
			}else{
				mayor++;
				tmp = nodoDoble;//regesamos a la cabeza de la lista
			}
		}
		}
		return mayor;
	}
int NodoDoble::maximoComunDivisor(NodoDoble *nodoDoble){
		NodoDoble *tmp=nodoDoble;
		int maximo{};
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
		}else{
			for(int i{1};i <= tmp->encontrarMenor(nodoDoble);i++){
			tmp = nodoDoble;
			while(tmp){
			if(tmp->getDato()%i == 0){
				maximo = i;
			}
			tmp=tmp->getSiguiente();
			}
		}
		}
		return maximo;
	}
void NodoDoble::mostrarListaDoblePorLaCola(NodoDoble *nodoDoble, int contarDatos) // Método en el cual se muestra la lista doble
{
	NodoDoble *aux,*aux2;	 // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
	aux = nodoDoble; // Apunto aux a pila,
	aux2 = nodoDoble;
	int posicion = contarDatos;
	while(aux2->getSiguiente()!=NULL)
	{
		aux2 = aux2->getSiguiente();
	}
	if (aux == NULL) // Si la lista doble esta vacia, si aux apunta a NULL.
	{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
	}
	else
	{
		while (aux2->getAnterior() != NULL) // Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
		{
			cout << "-> " << posicion << "\t" << aux2->getDato() << endl;
			posicion--;
			aux2 = aux2->getAnterior(); // Hago que se avance al siguiente nodo de la lista doble.
		}							   // Fin while()

		cout << "\nNumero de nodos en la lista doble: " << contarDatos << endl;
	}
}