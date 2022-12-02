#include "Login.h"
#include "Utileria.h"
#include <vector>

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> 

#define ENTER 13
#define BACKSPACE 8

using namespace std;

void Login::ingresar(){

    vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("david");
    usuarios.push_back("ariel");

    claves.push_back("123");
    claves.push_back("456");
   
    
    string usuario, password;

    bool ingresa = false;
    
    do {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        rewind(stdin);
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        rewind(stdin);
        caracter = _getch();

        password = "";

        while (caracter != ENTER){
            if (caracter != BACKSPACE){
                password.push_back(caracter);
                cout << "*";
            }
            else{
                if (password.length() > 0){
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = _getch();    
        }

        for (int i = 0; i < usuarios.size(); i++){
            if (usuarios[i] == usuario && claves[i] == password){
                ingresa = true;
                break;
            }
        }

        if (!ingresa) {
            Utileria::mostrar_mensaje("El usuario y/o password son incorrectos", TipoMensaje::Error);
            cin.get();
        }

    } while (ingresa == false);

    if (ingresa != false){
        Utileria::mostrar_mensaje("Bienvenido al sistema", TipoMensaje::Correcto);
    }
    cin.get();
}