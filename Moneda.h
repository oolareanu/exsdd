#pragma once

typedef struct
{
	char* taraemitenta;
	int valnom;
	float greutate;
	int anemitere;
} Moneda;

void afisareElem(const Moneda* moneda);