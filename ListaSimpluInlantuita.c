#include <stdio.h>
#include <stdlib.h>
#include "ListaSimpluInlantuita.h"
#include "Moneda.h"

void inseraremoneda(Nod** lista, Moneda* moneda)
{
	Nod* nou = malloc(sizeof(Nod));
	nou->inf = moneda;
	nou->urm = NULL;

	if (*lista)
	{
		Nod* aux = *lista;
		while (aux->urm)
		{
			aux = aux->urm;
		}
		aux->urm = nou;
	}
	else
	{
		*lista = nou;
	}
}

void traversare(Nod* lista)
{
	if (lista)
	{
		while (lista)
		{
			afisareElem(lista->inf);
			lista = lista->urm;
		}
	}
	else
	{
		printf("Lista e goala\n");
	}
}

void stergedupagreutate(Nod** lista, float greutatedata)
{
	if (*lista)
	{
		Nod* aux = *lista;
		Nod* anterior = NULL;

		while (aux)
		{
			if ((float)aux->inf->greutate == (float)greutatedata)
			{
				if (anterior)
				{
					Nod* sters = aux;
					anterior->urm = aux->urm;
					aux = aux->urm;
					free(sters->inf->taraemitenta);
					free(sters->inf);
					free(sters);
				}
				else
				{
					*lista = (*lista)->urm;
					free(aux->inf->taraemitenta);
					free(aux->inf);
					free(aux);
					aux = *lista;
				}
			}
			else
			{
				anterior = aux;
				aux = aux->urm;
			}
		}
	}
	else
	{
		printf("Lista este goala");
	}
}

void eliberare(Nod** lista)
{
	Nod* curent = *lista;
	while (curent)
	{
		Nod* urm = curent->urm;
		free(curent->inf->taraemitenta);
		free(curent->inf);
		free(curent);
		curent = urm;
	}
	*lista = NULL;
}

Moneda* getMonedaGrea(Nod* lista)
{
	if (lista == NULL) return NULL;

	Nod* aux = lista;
	Moneda* grea = lista->inf;

	while (aux != NULL)
	{
		if (aux->inf->greutate > grea->greutate)
		{
			grea = aux->inf;
		}
		aux = aux->urm;
	}

	Moneda* copie = (Moneda*)malloc(sizeof(Moneda));
	copie->taraemitenta = (char*)malloc(strlen(grea->taraemitenta) + 1);
	strcpy(copie->taraemitenta, grea->taraemitenta);
	copie->valnom = grea->valnom;
	copie->greutate = grea->greutate;
	copie->anemitere = grea->anemitere;

	return copie;
}