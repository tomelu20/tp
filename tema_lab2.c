#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nume[50];
    int nota;
} Student;
int comparare(const void *a, const void *b)
{
    int diff = ((Student *)b)->nota - ((Student *)a)->nota;
    if (diff == 0)
    {
        return strcmp(((Student *)a)->nume, ((Student *)b)->nume);
    }
    return diff;
}
int main()
{
    int n;
    scanf("%d", &n);
    Student studenti[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", studenti[i].nume, &studenti[i].nota);
    }
    qsort(studenti, n, sizeof(Student), comparare);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", studenti[i].nume, studenti[i].nota);
    }

    return 0;
}



#include <stdio.h>
typedef int (*Predicat)(int);
void eliminaElemente(int vector[], int *numarElemente, Predicat conditie)
{
    int i, j;
    for (i = 0, j = 0; i < *numarElemente; i++)
    {
        if (conditie(vector[i]))
        {
            vector[j] = vector[i];
            j++;
        }
    }
    *numarElemente = j;
}
int esteNegativ(int numar)
{
    return numar < 0;
}
int main()
{
    int vector[] = {1, -2, 3, -4, 5, -6};
    int numarElemente = sizeof(vector) / sizeof(vector[0]);
    for (int i = 0; i < numarElemente; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    eliminaElemente(vector, &numarElemente, esteNegativ);
    for (int i = 0; i < numarElemente; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
    return 0;
}




#include <stdio.h>
#include <stdlib.h>

int comparare(const void *a, const void *b)
{
    const float *floatA = (const float *)a;
    const float *floatB = (const float *)b;

    if (*floatA < *floatB) return -1;
    if (*floatA > *floatB) return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 10)
    {
        printf("Numarul introdus nu este valid. Programul se va inchide.\n");
        return 1;
    }
    float numere[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &numere[i]);
    }
    qsort(numere, n, sizeof(float), comparare);
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", numere[i]);
    }
    printf("\n");
    float x;
    scanf("%f", &x);
    float *rezultat = (float *)bsearch(&x, numere, n, sizeof(float), comparare);
    if (rezultat != NULL)
    {
        printf("Numarul %.2f a fost gasit in vectorul sortat.\n", x);
    }
    else
    {
        printf("Numarul %.2f nu a fost gasit in vectorul sortat.\n", x);
    }
    return 0;
}




#include <stdio.h>
#include <math.h>
typedef double (*FunctieMatematica)(double);
void tabelare(double a, double b, int n, FunctieMatematica f)
{
    double interval = (b - a) / n;
    printf("Tabelare pentru %s in intervalul [%.2f, %.2f] cu %d segmente:\n",
           (f == &cos) ? "cos" : ((f == &sqrt) ? "sqrt" : "fabs"), a, b, n);
    for (int i = 0; i <= n; i++)
    {
        double x = a + i * interval;
        printf("f(%.2f) = %.2f\n", x, f(x));
    }
}

int main()
{
    double a, b;
    int n;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%d", &n);
    tabelare(a, b, n, cos);
    tabelare(a, b, n, sqrt);
    tabelare(a, b, n, fabs);
    return 0;
}
