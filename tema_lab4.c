#include <stdio.h>
#include <string.h>

struct Student
{
    char nume[21];
    int nota;
};
struct Fisier {
    char nume[16];
    unsigned int dimensiune : 11;
    unsigned int tip : 2;
    unsigned int permisiuni : 1;
};
struct Fisier2 {
    char nume[16];  // Maxim 15 caractere + 1 pentru terminatorul de șir '\0'
    unsigned int dimensiune : 11;  // Număr maxim de 1024 octeți (10 biți, dar folosim 11 pentru a permite 0 până la 1024)
    unsigned int tip : 2;          // .txt - 0, .doc - 1, .xls - 2
    unsigned int permisiuni : 1;   // normal – 0, read-only – 1
};
int main()
{
    struct Student student;
    fgets(student.nume, 21, stdin);
    size_t len = strlen(student.nume);
    if (len > 0 && student.nume[len-1] == '\n')
    {
        student.nume[len-1] = '\0';
    }
    scanf("%d", &student.nota);
    printf("Nume: %s\n", student.nume);
    printf("Nota: %d\n", student.nota);

    struct Fisier fisier;
    fgets(fisier.nume, 16, stdin);
    size_t len = strlen(fisier.nume);
    if (len > 0 && fisier.nume[len-1] == '\n') {
        fisier.nume[len-1] = '\0';
    }
    scanf("%u", &fisier.dimensiune);

    if (fisier.dimensiune > 1024) {
        printf("Dimensiunea trebuie să fie maxim 1024 octeți.\n");
        return 1;
    }
    scanf("%u", &fisier.tip);
    if (fisier.tip > 2) {
        printf("Tipul fișierului trebuie să fie 0, 1 sau 2.\n");
        return 1;
    }
    scanf("%u", &fisier.permisiuni);
    if (fisier.permisiuni > 1) {
        printf("Permisiunile fișierului trebuie să fie 0 sau 1.\n");
        return 1;
    }
    printf("Nume: %s\n", fisier.nume);
    printf("Dimensiune: %u octeți\n", fisier.dimensiune);
    printf("Tip: ");
    switch (fisier.tip) {
        case 0: printf(".txt\n"); break;
        case 1: printf(".doc\n"); break;
        case 2: printf(".xls\n"); break;
        default: printf("necunoscut\n"); break;
    }
    printf("Permisiuni: %s\n", fisier.permisiuni ? "read-only" : "normal");

    struct Fisier2 *fisiere;
    int numarFisiere, i;
    FILE *file;

    printf("Introduceți numărul de fișiere (maxim 10): ");
    scanf("%d", &numarFisiere);

    if (numarFisiere > 10) {
        printf("Numărul maxim de fișiere este 10.\n");
        return 1;
    }

    fisiere = (struct Fisier2*)malloc(numarFisiere * sizeof(struct Fisier2));
    if (fisiere == NULL) {
        printf("Eroare la alocarea memoriei.\n");
        return 1;
    }
    for (i = 0; i < numarFisiere; i++) {
        printf("Introduceți numele fișierului %d (maxim 15 caractere): ", i + 1);
        getchar();
        fgets(fisiere[i].nume, 16, stdin);
        size_t len = strlen(fisiere[i].nume);
        if (len > 0 && fisiere[i].nume[len-1] == '\n') {
            fisiere[i].nume[len-1] = '\0';
        }
        printf("Introduceți dimensiunea fișierului %d (în octeți, maxim 1024): ", i + 1);
        scanf("%u", &fisiere[i].dimensiune);
        if (fisiere[i].dimensiune > 1024) {
            printf("Dimensiunea trebuie să fie maxim 1024 octeți.\n");
            free(fisiere);
            return 1;
        }
        printf("Introduceți tipul fișierului %d (.txt - 0, .doc - 1, .xls - 2): ", i + 1);
        scanf("%u", &fisiere[i].tip);
        if (fisiere[i].tip > 2) {
            printf("Tipul fișierului trebuie să fie 0, 1 sau 2.\n");
            free(fisiere);
            return 1;
        }
        printf("Introduceți permisiunile fișierului %d (normal - 0, read-only - 1): ", i + 1);
        scanf("%u", &fisiere[i].permisiuni);
        if (fisiere[i].permisiuni > 1) {
            printf("Permisiunile fișierului trebuie să fie 0 sau 1.\n");
            free(fisiere);
            return 1;
        }
    }
    file = fopen("memorie.txt", "w");
    if (file == NULL) {
        printf("Eroare la deschiderea fișierului.\n");
        free(fisiere);
        return 1;
    }
    for (i = 0; i < numarFisiere; i++) {
        fprintf(file, "Nume: %s\n", fisiere[i].nume);
        fprintf(file, "Dimensiune: %u octeți\n", fisiere[i].dimensiune);
        fprintf(file, "Tip: ");
        switch (fisiere[i].tip) {
            case 0: fprintf(file, ".txt\n"); break;
            case 1: fprintf(file, ".doc\n"); break;
            case 2: fprintf(file, ".xls\n"); break;
            default: fprintf(file, "necunoscut\n"); break;
        }
        fprintf(file, "Permisiuni: %s\n", fisiere[i].permisiuni ? "read-only" : "normal");
        fprintf(file, "\n");
    }
    fclose(file);
    free(fisiere);
    return 0;
}

