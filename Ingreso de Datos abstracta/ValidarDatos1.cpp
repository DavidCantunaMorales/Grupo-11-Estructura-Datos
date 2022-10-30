#include <iostream>
#include <conio.h>
#include "ValidarDatos.h"

class ValidarDatos1 : public ValidarDatos{
    public:
    char* validarEntero(char  const *mensaje);
    char* validarDoubles(char const *mensaje);
    char* validarLetras(char const *mensaje);
};

char* ValidarDatos1::validarEntero(char const *mensaje){
    char *dato=new char[10];
        char c;
        int i=0;
        printf("%s\n",mensaje);
        while((c=getch())!=13){
            if(c>='0'&& c<='9'){
                printf("%c",c);
                dato[i++]=c;
            }
        }
        dato[i]='\0';
        return dato;
} 

char* ValidarDatos1::validarDoubles(char const *mensaje){
    char *dato=new char[10];
    char c;
    int i=0, it_punto=0;
    std::cout<<mensaje<<std::endl;
    while((c=getch())!=13){
        if((c >= '0' && c <= '9') || c == '.'){
                if(c != '.'){
                    std::cout<<c;
                    dato[i++]=c;

                }else{
                    if(it_punto < 1){
                        std::cout<<c;
                        dato[i++]=c;
                        it_punto +=1;
                    }
                }
        }
    }
    dato[i]='\0';
    return dato;
}

char* ValidarDatos1::validarLetras(char const *mensaje){
    char *dato=new char[10];
    char c;
    int i=0;
    std::cout<<mensaje<<std::endl;
    while((c=getch())!=13){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' '){
            std::cout<<c;
            dato[i++] = c;
        }
    }
    return dato;
}