/***********************************************************************
 * Module:  MatrizRecursiva.h
 * Author:  Ariel Guevara, David Cantuña
 * Modified: domingo, 13 de noviembre de 2022 
 * Purpose: Declaration of the class Templates
 ***********************************************************************/

#if !defined(__Matriz_Recursiva)
#define __Matriz_Recursiva

class MatrizRecursiva
{
public:
    MatrizRecursiva();
    MatrizRecursiva(int d);
    void encerar(float** mat);
    void segmentar(float**mat,int d);
	void ingresar(float**mat,int d);
	void imprimir(float** mat,int d);
	void setDimension(float);
	void setMatriz(float** matri);
	float getDimension();
	float** getMatriz();
    int generar_aleatorio(int linf, int lsup);
    void multiplicacionRecursivaMatrices(float** mat1, float** mat2, float** matR, int f, int c); 
    void llenarMatrizRandom(float** matriz, int filas, int columnas);
private:
    float d;
    float** mat;
};


#endif