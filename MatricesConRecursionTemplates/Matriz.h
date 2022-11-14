#pragma once
template <typename T>
class Matriz{
private:
	T f, c; 
	T** ptr; 
public:
	Matriz();
	Matriz(T, T);
	T** getPtr();
	void asignarMemoria();
	void ingresar();
	void imprimir();

	// Sin recursividad
	Matriz<T> multiplicacion(Matriz<T>, T, T);
	Matriz<T> suma(Matriz<T>, T, T);

	// Con recursividad

	Matriz<T> sumaRecursiva(Matriz<T>, Matriz<T>, Matriz<T>, T, T);
	Matriz<T> multiplicacionRecursiva(Matriz<T>, Matriz<T>, Matriz<T>, T, T);
};

