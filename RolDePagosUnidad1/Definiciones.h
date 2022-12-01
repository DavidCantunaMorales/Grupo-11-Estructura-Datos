#pragma once

// que es un tipo definido por el usuario que está compuesto de un conjunto de constantes con nombre llamadas enumeradores

enum class TipoMensaje {
	Error,
	Correcto,
	Informativo
};

#define for_indexed(...) for_indexed_v(i, __VA_ARGS__)
#define for_indexed_v(v, ...) \
	if (std::size_t v = -1)   \
		for (__VA_ARGS__)     \
			if ((++v, true))

#define DOMINIO_EMAIL "espe.edu.ec"

#ifndef _MSC_VER
#define _getch(...) getch(__VA_ARGS__)
#endif