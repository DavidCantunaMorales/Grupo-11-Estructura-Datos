#pragma once
template <class T>
class Matriz
{
private:
	T d; // para guardar el dato
	T** mat; // usa un doble puntro ya que es una matriz con filas y columnas no como en el vector que solo tiene filas
public:
	Matriz();
	Matriz(T);
	void segmentar();
	void encerar();
	void ingresar();
	void imprimir();
	void setDimension(T);
	void setMatriz(T** matri);
	T getDimension();
	T** getMatriz();

	Matriz<T> multiplicacionMatrices(Matriz<T>);
	Matriz<T> sumaMatrices(Matriz<T>);
};