#pragma once
#include "ListaCircularDoble.h"

#include "rang/rang.hpp"
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
				std::getline(std::cin, leido), leido.empty())
				;
		}

		return leido;
	}

	static std::string leer_cadena_regex(const std::string etiqueta, std::string regex) {
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

	static int leer_entero(std::string etiqueta, int minimo = INT_MIN, int maximo = INT_MAX) {
		int leido;
		bool valido;

		do {
			std::cout << etiqueta;
			std::cin >> leido;

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();
		} while (!valido || leido < minimo || leido > maximo);

		return leido;
	}

	static bool cadenas_iguales(std::string a, std::string b) {
		a = trim_cadena(cadena_minusculas(a));
		b = trim_cadena(cadena_minusculas(b));

		return a == b;
	}

	static double leer_flotante(std::string etiqueta, double minimo = DBL_MIN, double maximo = DBL_MAX) {
		double leido;
		bool valido;

		do {
			std::cout << etiqueta;
			std::cin >> leido;

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();
		} while (!valido || leido < minimo || leido > maximo);

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

		std::string digits = cedula.substr(0, cedula.size() - 1);

		for (char& c : digits) {
			int digit = c - '0';
			if (i % 2 == 0) {
				sum_par += digit;
			}
			else {
				if ((digit * 2) > 9) {
					sum_impar += (digit * 2) - 9;
				}
				else {
					sum_impar += (digit * 2);
				}
			}
			i++;
		}

		sum = sum_par + sum_impar;

		int verifier = cedula.at(cedula.size() - 1) - '0';
		int higher = (10 - (sum % 10)) + sum;

		if (sum % 10 == 0) {
			return verifier == 0;
		}

		return (higher - sum) == verifier;
	}

	static ListaCircularDoble<std::string> dividir_cadena(std::string cadena, std::string delimitador) {
		ListaCircularDoble<std::string> partes;
		size_t start = 0;
		auto end = cadena.find(delimitador);

		while (end != std::string::npos) {
			std::string parte = cadena.substr(start, end - start);
			partes.insertarFinal(parte);
			start = end + delimitador.length();
			end = cadena.find(delimitador, start);
		}

		partes.insertarFinal(cadena.substr(start, end));
		return partes;
	}

	static std::string trim_cadena(std::string cadena) {
		// recorre el string de derecha a izquierda 
		auto wsfront = std::find_if_not(cadena.begin(), cadena.end(), [](int c) { 
			return std::isspace(c); 
		});
		// recorre el string de izquierda a derecha
		auto wsback = std::find_if_not(cadena.rbegin(), cadena.rend(), [](int c) { 
			return std::isspace(c); 
		}).base();

		return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
		// comprar los caracteres en blanco y si wsback <= wsfront 
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

	static std::string cadena_minusculas(std::string cadena) {
		std::string resultado(cadena);

		std::transform(resultado.begin(), resultado.end(), resultado.begin(), [](unsigned char c) {
			return std::tolower(c);
			});

		return resultado;
	}

	static void mostrar_mensaje(std::string mensaje, TipoMensaje tipo = TipoMensaje::Informativo) {
		rang::fg color;

		if (tipo == TipoMensaje::Informativo) {
			color = rang::fg::cyan;
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

	static bool existe_archivo(std::string nombre_archivo) {
		return std::ifstream(nombre_archivo.c_str()).good();
	}

	static std::string decimal_fixed(float valor, int precision = 2) {
		std::stringstream ss;
		ss << std::fixed << std::setprecision(precision) << valor;
		return ss.str();
	}
	
};