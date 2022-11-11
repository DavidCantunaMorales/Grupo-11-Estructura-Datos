#include <iostream>
#include <conio.h>
#include <string.h>
#include "ValidarDatos.h"

using namespace std;
int ValidarDatos::validarEntero(char* const &mensaje ){
    std::string dato;
    char c;
    int i=0, valor=0;
    cout<< mensaje;
    while((c=getch())!=13){
        if((c >= '0' && c <= '9') || c == 8){
            if(c == 8){
                dato.erase(i-1);
                i--;
                std::cout<<"\b";
                std::cout<<" ";
                std::cout<<"\b";
            }else{
                std::cout<<c;
                dato += c;
                i++;
            }
        }
    }
    valor = stoi(dato);
    return valor;
}

float ValidarDatos::validarDoubles(char* const &mensaje){
    std::string dato;
    char c;
    int i=0, it_punto=0;
    float valor=0;
    std::cout<<mensaje;
    while((c=getch())!=13){
        if((c >= '0' && c <= '9') || c == '.' || c == 8){
                if(c == 8){
                if(dato[i-1] == '.'){
                    it_punto = 0;
                }
                dato.erase(i-1);
                i--;
                std::cout<<"\b";
                std::cout<<" ";
                std::cout<<"\b";
            }else if(c != '.'){
                std::cout<<c;
                dato += c;
                i++;    
            }else{
                if (it_punto < 1){
                std::cout<<c;
                dato += c;
                i++;
                it_punto +=1;
                }              
            }
        }
    }
    valor = stof(dato);
    return valor;
}

std::string ValidarDatos::validarLetras(char* const &mensaje){
    std::string dato;
    char c;
    int i=0;
    std::cout<<mensaje<<std::endl;
    while((c=getch())!=13){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || c == 8){
            if(c == 8){
                dato.erase(i-1);
                i--;
                std::cout<<"\b";
                std::cout<<" ";
                std::cout<<"\b";
            }else{
                std::cout<<c;
                dato += c;
                i++;
            }
        }
    }
    return dato;
}
