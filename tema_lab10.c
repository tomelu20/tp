#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmmdc(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return cmmdc(b, a % b);
    }
}

int suma_cifrelor(int n)
{
    if (n < 10) {
        return n;
    } else {
        return n%10 + suma_cifrelor(n/10);
    }
}

int cifra_max(int n) {
    if (n < 10)
    {
        return n;
    }
    else
    {
        int ultima_cifra = n % 10;

        int max_rest = cifra_max(n / 10);

        if (ultima_cifra > max_rest)
        {
            return ultima_cifra;
        }
        else
        {
            return max_rest;
        }
    }
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

char* fib_string(int n, const char* s1, const char* s2) {
    if (n == 0)
    {
        return strdup(s1);
    }
    else if (n == 1)
    {
        return strdup(s2);
    }
    else
    {
        char* term1 = fib_string(n - 1, s1, s2);
        char* term2 = fib_string(n - 2, s1, s2);
        char* result = (char*)malloc(strlen(term1) + strlen(term2) + 1);
        strcpy(result, term1);
        strcat(result, term2);
        free(term1);
        free(term2);
        return result;
    }
}

int bsearch_rec(int v[], int stanga, int dreapta, int n) {
    if (stanga > dreapta) {
        return 0; // Elementul nu a fost găsit
    }

    int mijloc = (stanga + dreapta) / 2;

    if (v[mijloc] == n)
        return 1;

    else if (v[mijloc] < n)
        return bsearch_rec(v, mijloc + 1, dreapta, n);

    else
        return bsearch_rec(v, stanga, mijloc - 1, n);
}

int main() {
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    int result = cmmdc(num1, num2);
    printf("Cel mai mare divizor comun al numerelor %d și %d este: %d\n", num1, num2, result);
    int result = suma_cifrelor(num1);
    printf("%d\n",result);

    int numar;
    scanf("%d", &numar);

    int rezultat = cifra_max(numar);
    printf("Cifra maximă a numărului %d este: %d\n", numar, rezultat);

    int n;
    scanf("%d", &n);

    int rezultat = fib(n);
    printf("Al %d-lea termen Fibonacci este: %d\n", n, rezultat);

    int n;
    char s1[100], s2[100];

    printf("Introduceți valoarea lui n: ");
    scanf("%d", &n);

    printf("Introduceți primul șir (s1): ");
    scanf("%s", s1);

    printf("Introduceți al doilea șir (s2): ");
    scanf("%s", s2);

    char* rezultat = fib_string(n, s1, s2);
    printf("Termenul de pe poziția %d din șirul de caractere Fibonacci este: %s\n", n, rezultat);

    free(rezultat);

    int v[] = {1, 5, 8, 12, 17, 20, 33, 40};
    int dimensiune = sizeof(v) / sizeof(v[0]);
    int n = 33;

    int rezultat = bsearch_rec(v, 0, dimensiune - 1, n);

    if (rezultat) {
        printf("Elementul %d a fost gasit.\n", n);
    } else {
        printf("Elementul %d nu a fost gasit.\n", n);
    }

    return 0;
}
