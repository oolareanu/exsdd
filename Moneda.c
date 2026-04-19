#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Moneda.h"
#include "ListaSimpluInlantuita.h"

void afisareElem(const Moneda* moneda)
{
	printf("Moneda este din (tara) %s, are valoarea nominala %d, greutatea %.1f si a fost emisa in anul %d\n", moneda->taraemitenta, moneda->valnom, moneda->greutate, moneda->anemitere);
}