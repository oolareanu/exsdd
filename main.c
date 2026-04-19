#include <stdio.h>
#include <stdlib.h>
#include "Moneda.h"
#include "ListaSimpluInlantuita.h"

int main()
{
	struct Nod* lista = NULL;

	Moneda* m1 = malloc(sizeof(Moneda));
	m1->taraemitenta = malloc(strlen("Rusia") + 1);
	strcpy(m1->taraemitenta, "Rusia");
	m1->valnom = 57;
	m1->greutate = 3;
	m1->anemitere = 1704;

	Moneda* m2 = malloc(sizeof(Moneda));
	m2->taraemitenta = malloc(strlen("Noua Zeelanda") + 1);
	strcpy(m2->taraemitenta, "Noua Zeelanda");
	m2->valnom = 255;
	m2->greutate = 10;
	m2->anemitere = 1967;

	Moneda* m3 = malloc(sizeof(Moneda));
	m3->taraemitenta = malloc(strlen("China") + 1);
	strcpy(m3->taraemitenta, "China");
	m3->valnom = 63;
	m3->greutate = 6.1;
	m3->anemitere = 1948;

	Moneda* m4 = malloc(sizeof(Moneda));
	m4->taraemitenta = malloc(strlen("Argentina") + 1);
	strcpy(m4->taraemitenta, "Argentina");
	m4->valnom = 32;
	m4->greutate = 6.4;
	m4->anemitere = 1992;

	Moneda* m5 = malloc(sizeof(Moneda));
	m5->taraemitenta = malloc(strlen("Congo") + 1);
	strcpy(m5->taraemitenta, "Congo");
	m5->valnom = 19;
	m5->greutate = 8.8;
	m5->anemitere = 1887;

	inseraremoneda(&lista, m1);
	inseraremoneda(&lista, m2);
	inseraremoneda(&lista, m3);
	inseraremoneda(&lista, m4);
	inseraremoneda(&lista, m5);

	traversare(lista);

	printf("\n");
	printf("\n");

	/*stergedupagreutate(&lista, 6.1);

	traversare(lista);*/

	Moneda* monmaxgrea = getMonedaGrea(lista);

	/*if (monmaxgrea != NULL)
	{
		afisareElem(monmaxgrea);
		free(monmaxgrea->taraemitenta);
		free(monmaxgrea);
	}*/

	/*Nod* curent = lista;
	while (curent != NULL)
	{
		free(curent->inf->taraemitenta);
		free(curent->inf);
		curent = curent->urm;
	}
	lista = NULL;*/

	eliberare(&lista);

	return 0;
}