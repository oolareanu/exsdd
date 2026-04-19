Moneda* filtreazaMonedeInVector(Nod* lista, int anPrag, int* dimensiune) {
    if (lista == NULL) {
        *dimensiune = 0;
        return NULL;
    }

    // Pasul 1: Numărăm câte monede respectă criteriul
    int contor = 0;
    Nod* aux = lista;
    while (aux != NULL) {
        if (aux->inf->anemitere > anPrag) {
            contor++;
        }
        aux = aux->urm;
    }

    if (contor == 0) {
        *dimensiune = 0;
        return NULL;
    }

    // Pasul 2: Alocăm dinamic vectorul de structuri Moneda
    // Folosim safe_malloc-ul creat anterior
    Moneda* vector = (Moneda*)safe_malloc(contor * sizeof(Moneda));

    // Pasul 3: Populăm vectorul cu Deep Copy
    aux = lista;
    int i = 0;
    while (aux != NULL) {
        if (aux->inf->anemitere > anPrag) {
            // Realizăm deep copy pentru fiecare element din vector
            vector[i].taraemitenta = (char*)safe_malloc(strlen(aux->inf->taraemitenta) + 1);
            strcpy(vector[i].taraemitenta, aux->inf->taraemitenta);

            vector[i].valnom = aux->inf->valnom;
            vector[i].greutate = aux->inf->greutate;
            vector[i].anemitere = aux->inf->anemitere;

            i++;
        }
        aux = aux->urm;
    }

    *dimensiune = contor; // "Returnăm" dimensiunea prin pointer
    return vector;
}


/////////////////////// main.c


int nrElemente = 0;
Moneda* vectorMonede = filtreazaMonedeInVector(lista, 1900, &nrElemente);

if (vectorMonede != NULL) {
    printf("\nAm gasit % d monede dupa anul 1900:\n", nrElemente);
    for (int i = 0; i < nrElemente; i++) {
        // Observă folosirea punctului (.) pentru că vector[i] este direct structura, nu pointer
        printf(" % d.Tara: % s, An : % d\n", i + 1, vectorMonede[i].taraemitenta, vectorMonede[i].anemitere);
    }

    // Nu uita să eliberezi memoria pentru vector la final!
    for (int i = 0; i < nrElemente; i++) {
        free(vectorMonede[i].taraemitenta);
    }
    free(vectorMonede);
}