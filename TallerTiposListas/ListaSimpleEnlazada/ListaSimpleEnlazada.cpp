#include <iostream>
#include "Lista.h"
#include "ValidarDatos.h"

using namespace std;

int main(){

    Lista lst, lsts, lsta;
    ValidarDatos val;

    int opcion, num, mcd, mcm;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\nOPERACIONES CON LISTAS SIMPLES" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. ELIMINAR" << endl;
        cout << "3. BUSCAR" << endl;
        cout << "4. MOSTRAR" << endl;
        cout << "5. MCD" << endl;
        cout << "6. MCM" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            num = val.validarEntero("Ingrese el numero: ");
            cout << endl;
            lst.insertar(num);
            system("pause>nul"); // Pausa
            break;

        case 2:
            num = val.validarEntero("Ingrese el numero: ");
            cout << endl;
            lst.eliminar(num);
            system("pause>nul"); // Pausa
            break;

        case 3:
            num = val.validarEntero("Ingrese el numero: ");
            cout << endl;
            lst.buscar(num);
            system("pause>nul"); // Pausa            
            break;

        case 4:
            lst.mostrar();
            system("pause>nul"); // Pausa            
            break;

        case 5:
            cout << "MOSTRANDO MCD" << endl;
            mcd = lsts.maximoComunDivisor(lst);
            cout << endl;
            cout << mcd << endl;
            system("pause>nul"); // Pausa                
            break;

        case 6:
            cout << "MOSTRANDO MCM" << endl;
            mcm = lsts.minimoComunMultiplo(lst);
            cout << endl;
            cout << mcm << endl;
            system("pause>nul"); // Pausa                
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);


    /*
    //int num = 0;
    //cont = 0;
    int cont = val.validarEntero("Cuantos elementos desea insertar: ");
    cout << endl;
    /*
    //cout << "Cuantos elementos desea insertar: ";
    //cin >> cont;
    
    while (cont <= 1) {
        cout << "La lista debe tener mas de un elemento.\n";
        cout << "Cuantos elementos desea insertar: ";
        cin >> cont;
    }
    do {
        
        //cout << "Ingrese el numero: ";
        //cin >> num;
        
        int num = val.validarEntero("Ingrese el numero: ");
        cout << endl;
        lst.insertar(num);
        cont--;
    } while (cont != 0);

    lst.mostrar();
    cout << "La suma de los elementos pares es: " << lst.sumarPares() << endl;

        cout << "MOSTRANDO MCD" << endl;
        int mcd = lsts.maximoComunDivisor(lst);
        cout << endl;
        cout << mcd << endl;

        cout << "MOSTRANDO MCM" << endl;
        int mcm = lsts.minimoComunMultiplo(lst);
        cout << endl;
        cout << mcm << endl;

    //lsta = lsts.guardarLista(lst);
    //lsta.mostrar();
    

    
    cout << "\nEscriba el indice de elemento que desea borrar: ";
    cin >> cont;

    lst.eliminar(cont);
    lst.mostrar();
    cout << "La sumas de los elementos es: " << lst.sumaTotal();
    std::cout << "\n";
    

    */

    return 0;
}

