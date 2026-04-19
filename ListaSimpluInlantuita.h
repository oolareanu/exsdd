#pragma once

#include "Moneda.h"

typedef struct Nod
{
	Moneda* inf;
	struct Nod* urm;
} Nod;

void inseraremoneda(Nod** lista, Moneda* moneda);
void traversare(Nod* lista);
void stergedupagreutate(Nod** lista, float greutatedata);
void eliberare(Nod** lista);
Moneda* getMonedaGrea(Nod* lista);