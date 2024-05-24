#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int valoare;
    struct Nod* urmator;
    struct Nod* anterior;
} Nod;

typedef struct Lista {
    struct Nod* cap;
    struct Nod* coada;
} Lista;

Nod* creeazaNod(int valoare) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if (nodNou == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    nodNou->valoare = valoare;
    nodNou->urmator = NULL;
    nodNou->anterior = NULL;
    return nodNou;
}

void adaugaLaSfarsit(Lista* lista, int valoare) {
    Nod* nodNou = creeazaNod(valoare);
    if (lista->cap == NULL) {
        lista->cap = nodNou;
        lista->coada = nodNou;
    } else {
        lista->coada->urmator = nodNou;
        nodNou->anterior = lista->coada;
        lista->coada = nodNou;
    }
}

void afiseazaLista(Lista* lista) {
    Nod* curent = lista->cap;
    while (curent != NULL) {
        printf("%d ", curent->valoare);
        curent = curent->urmator;
    }
    printf("\n");
}

void concateneazaListe(Lista* lista1, Lista* lista2) {
    if (lista1->cap == NULL) {
        lista1->cap = lista2->cap;
        lista1->coada = lista2->coada;
    } else {
        lista1->coada->urmator = lista2->cap;
        if (lista2->cap != NULL) {
            lista2->cap->anterior = lista1->coada;
        }
        lista1->coada = lista2->coada;
    }
    free(lista2);
}

typedef struct Nod {
    int valoare;
    struct Nod* urmator;
    struct Nod* anterior;
} Nod;

Nod* creeazaNod(int valoare) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if (nodNou == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    nodNou->valoare = valoare;
    nodNou->urmator = NULL;
    nodNou->anterior = NULL;
    return nodNou;
}

void adaugaLaSfarsit(Nod** cap, int valoare) {
    Nod* nodNou = creeazaNod(valoare);
    if (*cap == NULL) {
        *cap = nodNou;
    } else {
        Nod* curent = *cap;
        while (curent->urmator != NULL) {
            curent = curent->urmator;
        }
        curent->urmator = nodNou;
        nodNou->anterior = curent;
    }
}

void afiseazaLista(Nod* cap) {
    Nod* curent = cap;
    while (curent != NULL) {
        printf("%d ", curent->valoare);
        curent = curent->urmator;
    }
    printf("\n");
}

void interschimbaPerechi(Nod** cap) {
    if (*cap == NULL || (*cap)->urmator == NULL) {
        return;
    }

    Nod* primul = *cap;
    while (primul != NULL && primul->urmator != NULL) {
        Nod* primulAnterior = primul->anterior;
        Nod* alDoilea = primul->urmator;
        Nod* alDoileaUrmator = alDoilea->urmator;
        if (primulAnterior != NULL) {
            primulAnterior->urmator = alDoilea;
        } else {
            *cap = alDoilea;
        }
        alDoilea->anterior = primulAnterior;
        alDoilea->urmator = primul;
        primul->anterior = alDoilea;
        primul->urmator = alDoileaUrmator;
        if (alDoileaUrmator != NULL) {
            alDoileaUrmator->anterior = primul;
        }
        primul = alDoileaUrmator;
    }
}

typedef struct Nod {
    int valoare;
    struct Nod* urmator;
    struct Nod* anterior;
} Nod;

Nod* creeazaNod(int valoare) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if (nodNou == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    nodNou->valoare = valoare;
    nodNou->urmator = NULL;
    nodNou->anterior = NULL;
    return nodNou;
}

void adaugaLaSfarsit(Nod** cap, int valoare) {
    Nod* nodNou = creeazaNod(valoare);
    if (*cap == NULL) {
        *cap = nodNou;
    } else {
        Nod* curent = *cap;
        while (curent->urmator != NULL) {
            curent = curent->urmator;
        }
        curent->urmator = nodNou;
        nodNou->anterior = curent;
    }
}

void stergePrimulSiUltimul(Nod** cap) {
    if (*cap == NULL || (*cap)->urmator == NULL) {
        return;
    }

    Nod* primul = *cap;
    *cap = (*cap)->urmator;
    (*cap)->anterior = NULL;
    free(primul);

    Nod* curent = *cap;
    while (curent->urmator->urmator != NULL) {
        curent = curent->urmator;
    }
    Nod* ultimul = curent->urmator;
    curent->urmator = NULL;
    free(ultimul);
}

void afiseazaLista(Nod* cap) {
    Nod* curent = cap;
    while (curent != NULL) {
        printf("%d ", curent->valoare);
        curent = curent->urmator;
    }
    printf("\n");
}

typedef struct Nod {
    int valoare;
    struct Nod* urmator;
} Nod;

Nod* creeazaNod(int valoare) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if (nodNou == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    nodNou->valoare = valoare;
    nodNou->urmator = NULL;
    return nodNou;
}

void adaugaLaSfarsit(Nod** cap, int valoare) {
    Nod* nodNou = creeazaNod(valoare);
    if (*cap == NULL) {
        *cap = nodNou;
    } else {
        Nod* curent = *cap;
        while (curent->urmator != NULL) {
            curent = curent->urmator;
        }
        curent->urmator = nodNou;
    }
}

void stergeElementelePare(Nod** cap) {
    if (*cap == NULL) {
        return;
    }

    while (*cap != NULL && (*cap)->valoare % 2 == 0) {
        Nod* temp = *cap;
        *cap = (*cap)->urmator;
        free(temp);
    }

    Nod* curent = *cap;
    while (curent != NULL && curent->urmator != NULL) {
        if (curent->urmator->valoare % 2 == 0) {
            Nod* temp = curent->urmator;
            curent->urmator = temp->urmator;
            free(temp);
        } else {
            curent = curent->urmator;
        }
    }
}

void afiseazaLista(Nod* cap) {
    Nod* curent = cap;
    while (curent != NULL) {
        printf("%d ", curent->valoare);
        curent = curent->urmator;
    }
    printf("\n");
}


int main() {
    FILE* fisier;
    int numar;
    Lista* listaPare = (Lista*)malloc(sizeof(Lista));
    Lista* listaImpare = (Lista*)malloc(sizeof(Lista));
    if (listaPare == NULL || listaImpare == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    listaPare->cap = NULL;
    listaPare->coada = NULL;
    listaImpare->cap = NULL;
    listaImpare->coada = NULL;

    fisier = fopen("numere.txt", "r");
    if (fisier == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(1);
    }
    while (fscanf(fisier, "%d", &numar) != EOF) {
        if (numar % 2 == 0) {
            adaugaLaSfarsit(listaPare, numar);
        } else {
            adaugaLaSfarsit(listaImpare, numar);
        }
    }
    concateneazaListe(listaPare, listaImpare);
    printf("Lista rezultata: ");
    afiseazaLista(listaPare);
    fclose(fisier);
    Nod* curent = listaPare->cap;
    Nod* urmator;
    while (curent != NULL) {
       urmator = curent->urmator;
        free(curent);
        curent = urmator;
    }
    free(listaPare);

    Nod* cap = NULL;
    adaugaLaSfarsit(&cap, 1);
    adaugaLaSfarsit(&cap, 2);
    adaugaLaSfarsit(&cap, 3);
    adaugaLaSfarsit(&cap, 4);
    adaugaLaSfarsit(&cap, 5);
    adaugaLaSfarsit(&cap, 6);
    adaugaLaSfarsit(&cap, 7);
    adaugaLaSfarsit(&cap, 8);
    printf("Lista initiala: ");
    afiseazaLista(cap);
    interschimbaPerechi(&cap);
    printf("Lista dupa interschimbarea perechilor: ");
    afiseazaLista(cap);
    while (cap != NULL) {
        Nod* temp = cap;
        cap = cap->urmator;
        free(temp);
    }

    Nod* cap = NULL;
    adaugaLaSfarsit(&cap, 1);
    adaugaLaSfarsit(&cap, 2);
    adaugaLaSfarsit(&cap, 3);
    adaugaLaSfarsit(&cap, 4);
    adaugaLaSfarsit(&cap, 5);
    afiseazaLista(cap);
    stergePrimulSiUltimul(&cap);
    afiseazaLista(cap);
    while (cap != NULL) {
        Nod* temp = cap;
        cap = cap->urmator;
        free(temp);
    }

    Nod* cap = NULL;
    adaugaLaSfarsit(&cap, 1);
    adaugaLaSfarsit(&cap, 2);
    adaugaLaSfarsit(&cap, 3);
    adaugaLaSfarsit(&cap, 4);
    adaugaLaSfarsit(&cap, 5);
    adaugaLaSfarsit(&cap, 6);
    afiseazaLista(cap);
    stergeElementelePare(&cap);
    afiseazaLista(cap);
    while (cap != NULL) {
        Nod* temp = cap;
        cap = cap->urmator;
        free(temp);
    }

    return 0;
}
