#if !defined(__Matriz_h)
#define __Matriz_h
#define TAM 10
class Matriz{
    public:
    bool validarMatrices(int f1, int c1, int f2, int c2);
    int generar_aleatorio(int linf, int lsup);
    void llenarMatrizRandom(float matriz[TAM][TAM], int filas, int columnas);
    void llenarMatriz(float matriz[TAM][TAM], int filas, int columnas);
    void sumaDeMatrices(float matriz1[TAM][TAM],float matriz2[TAM][TAM],
                        int f1, int c1, int f2, int c2);
    void multiplicacionDeMatrices(float matriz1[TAM][TAM],float matriz2[TAM][TAM],
                        int f1, int c1, int f2, int c2);
    private:
    float matriz[TAM][TAM];
};

#endif
