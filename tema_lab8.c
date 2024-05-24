#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod
{
    char linie[1000];
    struct Nod* urmator;
    struct Nod* anterior;
} Nod;

typedef struct Lista
{
    Nod* cap;
    Nod* coada;
} Lista;

Nod* creeazaNod(const char* linie)
{
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    if (nodNou == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    strncpy(nodNou->linie, linie, 1000);
    nodNou->urmator = NULL;
    nodNou->anterior = NULL;
    return nodNou;
}

Lista* creeazaLista()
{
    Lista* listaNoua = (Lista*)malloc(sizeof(Lista));
    if (listaNoua == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    listaNoua->cap = NULL;
    listaNoua->coada = NULL;
    return listaNoua;
}

typedef struct Produs
{
    char nume[100];
    float pret;
    struct Produs* urmator;
    struct Produs* anterior;
} Produs;

typedef struct Categorie
{
    char nume[100];
    struct Produs* produseCap;
    struct Produs* produseCoada;
    struct Categorie* urmator;
    struct Categorie* anterior;
} Categorie;

typedef struct ListaCategorii
{
    struct Categorie* cap;
    struct Categorie* coada;
} ListaCategorii;

Produs* creeazaProdus(const char* nume, float pret)
{
    Produs* produsNou = (Produs*)malloc(sizeof(Produs));
    if (produsNou == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    strncpy(produsNou->nume, nume, 100);
    produsNou->pret = pret;
    produsNou->urmator = NULL;
    produsNou->anterior = NULL;
    return produsNou;
}

Categorie* creeazaCategorie(const char* nume)
{
    Categorie* categorieNoua = (Categorie*)malloc(sizeof(Categorie));
    if (categorieNoua == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    strncpy(categorieNoua->nume, nume, 100);
    categorieNoua->produseCap = NULL;
    categorieNoua->produseCoada = NULL;
    categorieNoua->urmator = NULL;
    categorieNoua->anterior = NULL;
    return categorieNoua;
}

ListaCategorii* creeazaListaCategorii()
{
    ListaCategorii* listaNoua = (ListaCategorii*)malloc(sizeof(ListaCategorii));
    if (listaNoua == NULL)
    {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    listaNoua->cap = NULL;
    listaNoua->coada = NULL;
    return listaNoua;
}
