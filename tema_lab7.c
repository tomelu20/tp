#include <stdio.h>

int suntIdentice(int* lista1, int lungime1, int* lista2, int lungime2)
{
    if (lungime1 != lungime2)
    {
        return 0;
    }

    for (int i = 0; i < lungime1; i++)
    {
        if (lista1[i] != lista2[i])
        {
            return 0;
        }
    }
    return 1;
}

void inverseazaLista(int* lista, int lungime)
{
    for (int i = 0; i < lungime / 2; i++)
    {
        int temp = lista[i];
        lista[i] = lista[lungime - 1 - i];
        lista[lungime - 1 - i] = temp;
    }
}

int suntEgale(int* lista1, int lungime1, int* lista2, int lungime2)
{
    if (lungime1 != lungime2)
    {
        return 0;
    }
    int min_val = lista1[0];
    int max_val = lista1[0];

    for (int i = 0; i < lungime1; i++)
    {
        if (lista1[i] < min_val)
        {
            min_val = lista1[i];
        }
        if (lista1[i] > max_val)
        {
            max_val = lista1[i];
        }
    }

    for (int i = 0; i < lungime2; i++)
    {
        if (lista2[i] < min_val)
        {
            min_val = lista2[i];
        }
        if (lista2[i] > max_val)
        {
            max_val = lista2[i];
        }
    }

    int range = max_val - min_val + 1;

    int* frecvente1 = (int*)calloc(range, sizeof(int));
    int* frecvente2 = (int*)calloc(range, sizeof(int));

    if (frecvente1 == NULL || frecvente2 == NULL)
    {
        printf("eroare alocare\n");
        return 0;
    }

    for (int i = 0; i < lungime1; i++)
    {
        frecvente1[lista1[i] - min_val]++;
    }

    for (int i = 0; i < lungime2; i++)
    {
        frecvente2[lista2[i] - min_val]++;
    }

    for (int i = 0; i < range; i++)
    {
        if (frecvente1[i] != frecvente2[i])
        {
            free(frecvente1);
            free(frecvente2);
            return 0;
        }
    }

    free(frecvente1);
    free(frecvente2);
    return 1;
}

void sterge(Lista* lista, int valoare)
{
    if (lista->cap == NULL)
    {
        return;
    }

    if (lista->cap->valoare == valoare)
    {
        Nod* deSters = lista->cap;
        lista->cap = lista->cap->urmator;
        if (lista->cap == NULL)
        {
            lista->coada = NULL;
        }
        free(deSters);
        return;
    }
    Nod* curent = lista->cap;
    while (curent->urmator != NULL && curent->urmator->valoare != valoare)
    {
        curent = curent->urmator;
    }
    if (curent->urmator == NULL)
    {
        return;
    }
    Nod* deSters = curent->urmator;
    curent->urmator = deSters->urmator;
    if (deSters == lista->coada)
    {
        lista->coada = curent;
    }
    free(deSters);
}

int main()
{

    int lista1[] = {1, 2, 3, 4, 5};
    int lista2[] = {1, 2, 3, 4, 5};
    int lista3[] = {1, 2, 3, 4, 6};
    int lungime1 = sizeof(lista1) / sizeof(lista1[0]);
    int lungime2 = sizeof(lista2) / sizeof(lista2[0]);
    int lungime3 = sizeof(lista3) / sizeof(lista3[0]);
    printf("Lista1 și Lista2 sunt identice? %d\n", suntIdentice(lista1, lungime1, lista2, lungime2));
    printf("Lista1 și Lista3 sunt identice? %d\n", suntIdentice(lista1, lungime1, lista3, lungime3));

    int lista[] = {1, 2, 3, 4, 5};
    int lungime = sizeof(lista) / sizeof(lista[0]);
    printf("Lista originală: ");
    for (int i = 0; i < lungime; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
    inverseazaLista(lista, lungime);
    printf("Lista inversată: ");
    for (int i = 0; i < lungime; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");

    int lista1[] = {1, 7, 3, 1, 3};
    int lista2[] = {7, 1, 3, 7, 1};
    int lungime1 = sizeof(lista1) / sizeof(lista1[0]);
    int lungime2 = sizeof(lista2) / sizeof(lista2[0]);
    printf("Listele sunt egale? %d\n", suntEgale(lista1, lungime1, lista2, lungime2));
    int lista3[] = {1, 2};
    int lista4[] = {2};
    int lungime3 = sizeof(lista3) / sizeof(lista3[0]);
    int lungime4 = sizeof(lista4) / sizeof(lista4[0]);
    printf("Listele sunt egale? %d\n", suntEgale(lista3, lungime3, lista4, lungime4));

    Lista* lista = creeazaLista();

    adaugaLaSfarsit(lista, 1);
    adaugaLaSfarsit(lista, 2);
    adaugaLaSfarsit(lista, 3);
    adaugaLaSfarsit(lista, 4);

    printf("Lista inițială: ");
    afiseazaLista(lista);

    sterge(lista, 3);
    printf("Lista după ștergerea lui 3: ");
    afiseazaLista(lista);

    sterge(lista, 1);
    printf("Lista după ștergerea lui 1: ");
    afiseazaLista(lista);

    sterge(lista, 4);
    printf("Lista după ștergerea lui 4: ");
    afiseazaLista(lista);

    sterge(lista, 5);
    printf("Lista după încercarea de ștergere a lui 5 (inexistent): ");
    afiseazaLista(lista)

    return 0;
}

