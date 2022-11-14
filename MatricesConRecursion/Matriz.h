#pragma once

class Matriz{
private:
	int f, c;
	int** ptr;
public:
	Matriz();
	Matriz(int, int);
	int** getPtr();
	void asignarMemoria();
	void ingresar();
	void imprimir();

	Matriz multiplicacion(Matriz, int, int);
	Matriz suma(Matriz, int, int);

	Matriz sumaRecursiva(Matriz, Matriz, Matriz, int, int);
	
	Matriz multiplicacionRecursiva(Matriz, Matriz, Matriz, int, int);


};
