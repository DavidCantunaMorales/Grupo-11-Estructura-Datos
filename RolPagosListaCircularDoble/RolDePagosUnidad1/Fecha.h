#pragma once
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Fecha {
public:
    void obtenerFechaSistema() {
        time_t now = time(0);

        tm* time = localtime(&now);

        vector<string> diaSemana;
        diaSemana.push_back("Domingo");
        diaSemana.push_back("Lunes");
        diaSemana.push_back("Martes");
        diaSemana.push_back("Miercoles");
        diaSemana.push_back("Jueves");
        diaSemana.push_back("Viernes");
        diaSemana.push_back("Sabado");

        vector<string> mes;
        mes.push_back("ENERO");
        mes.push_back("FEBRERO");
        mes.push_back("MARZO");
        mes.push_back("ABRIL");
        mes.push_back("MAYO");
        mes.push_back("JUNIO");
        mes.push_back("JULIO");
        mes.push_back("AGOSTO");
        mes.push_back("SEPTIEMBRE");
        mes.push_back("OCTUBRE");
        mes.push_back("NOVIEMBRE");
        mes.push_back("DICIEMBRE");

        int anio = 1900 + time->tm_year;

        cout << "ROL DE PAGO DEL MES DE: " << mes[time->tm_mon] << " DEL " << anio << endl;
    }
};


