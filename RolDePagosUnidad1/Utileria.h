#pragma once
#include "ListaCircularDoble.h"

#include "rang.hpp"
#include "Definiciones.h"

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <random>
#include <cctype>
#include <regex>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <Windows.h>
#include <conio.h>

class Utileria {
public:

	static std::string leer_cadena(const std::string etiqueta, bool permitir_vacio = false) {
		std::string leido;

		if (permitir_vacio) {
			std::getline(std::cin, leido);
		}
		else {
			while ((std::cout << etiqueta),
				std::getline(std::cin, leido), leido.empty());
		}

		return leido;
	}

	static std::string leerCadena1(const std::string etiqueta, std::string regex) {
		rewind(stdin);
		std::string leido;
		std::regex cadena_regex(regex);

		do {
			leido = leer_cadena(etiqueta);

			if (!std::regex_match(leido, cadena_regex)) {
				mostrar_mensaje("Formato invalido", TipoMensaje::Error);
			}
		} while (!std::regex_match(leido, cadena_regex));
		rewind(stdin);
		return leido;
	}

	static bool cedula_valida(const std::string cedula) {
		if (cedula.length() != 10) {
			return false;
		}

		int sum_par = 0;
		int sum_impar = 0;
		int sum;
		int i = 1;

		std::string digitos = cedula.substr(0, cedula.size() - 1);

		for (char& c : digitos) {
			int digito = c - '0';
			if (i % 2 == 0) {
				sum_par += digito;
			}
			else {
				if ((digito * 2) > 9) {
					sum_impar += (digito * 2) - 9;
				}
				else {
					sum_impar += (digito * 2);
				}
			}
			i++;
		}

		sum = sum_par + sum_impar;

		int verificar = cedula.at(cedula.size() - 1) - '0';
		int bandera = (10 - (sum % 10)) + sum;

		if (sum % 10 == 0) {
			return verificar == 0;
		}

		return (bandera - sum) == verificar;
	}

	// dividir la cadena nos sirve para separar las cadenas por el delimitador ","
	static ListaCircularDoble<std::string> dividir_cadena(std::string cadena, std::string delimitador) {
		ListaCircularDoble<std::string> partes;
		size_t inicio = 0;
		auto final = cadena.find(delimitador);

		while (final != std::string::npos) {
			std::string parte = cadena.substr(inicio, final - inicio);
			partes.insertarFinal(parte);
			inicio = final + delimitador.length();
			final = cadena.find(delimitador, inicio);
		}

		partes.insertarFinal(cadena.substr(inicio, final));
		return partes;
	}

	// verificar el numero de caracteres de la cadena
	static std::string trim_cadena(std::string cadena) {
		// recorre el string de derecha a izquierda 
		auto wsInicio = std::find_if_not(cadena.begin(), cadena.end(), [](int c) { 
			return std::isspace(c); 
		});
		// recorre el string de izquierda a derecha
		auto wsFinal = std::find_if_not(cadena.rbegin(), cadena.rend(), [](int c) { 
			return std::isspace(c); 
		}).base();

		return (wsFinal <= wsInicio ? std::string() : std::string(wsInicio, wsFinal));
		// comprar los caracteres en blanco y si wsFinal <= wsInicio 
		// nos devuelve std::string(); caso contrario std::string(wsfront, wsback)
	}

	static void leer_lineas(std::string nombre_archivo, std::function<void(std::string linea, ListaCircularDoble<std::string> datos)> callback) {
		std::ifstream archivo(nombre_archivo);
		std::string linea;

		while (std::getline(archivo, linea)) {
			linea = Utileria::trim_cadena(linea);

			if (linea.empty()) {  // confirma si el string esta vacio
				continue;
			}

			auto columnas = Utileria::dividir_cadena(linea, ",");  // separa las cadenas con la coma
			int indice = 0;

			// usamos la funciona lamba para recorrer toda nuestra lista y obtener en cada nodo los valores correspondientes
			columnas.recorrer([&](std::string token) {
				columnas.obtenerNodo(indice)->setValor(Utileria::trim_cadena(token));
				indice++;
			});

			// llamamos a la funcion lamda 
			callback(linea, columnas);
		}

		archivo.close();
	}

	static void mostrar_mensaje(std::string mensaje, TipoMensaje tipo = TipoMensaje::Informativo) {
		rang::fg color;

		if (tipo == TipoMensaje::Informativo) {
			//color = rang::fg::cyan;
			color = rang::fg::yellow;
		}
		else if (tipo == TipoMensaje::Correcto) {
			color = rang::fg::green;
			
		}
		else if (tipo == TipoMensaje::Error) {
			color = rang::fg::red;
		}
		else {
			color = rang::fg::cyan;
		}

		std::cout
			<< std::endl << rang::style::bold << color
			<< "(" << mensaje << ")"
			<< std::endl << rang::style::reset;
	}

};