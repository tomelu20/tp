#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
void print_hexdump(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Eroare la deschiderea fișierului");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[16];
    size_t bytes_read;
    unsigned long offset = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("%08lx  ", offset);

        for (size_t i = 0; i < sizeof(buffer); ++i) {
            if (i < bytes_read) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   ");
            }

            if (i == 7) {
                printf(" ");
            }
        }

        printf(" |");
        for (size_t i = 0; i < bytes_read; ++i) {
            if (buffer[i] >= 32 && buffer[i] <= 255) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        if (bytes_read < sizeof(buffer)) {
            for (size_t i = bytes_read; i < sizeof(buffer); ++i) {
                printf(" ");
            }
        }
        printf("|\n");
        offset += bytes_read;
    }
    fclose(file);
}

void concatenate_files(int num_files, char *file_names[]) {
    FILE *dest_file = fopen(file_names[num_files - 1], "wb");
    if (dest_file == NULL) {
        perror("Eroare la deschiderea fișierului destinație");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    for (int i = 0; i < num_files - 1; i++) {
        FILE *src_file = fopen(file_names[i], "rb");
        if (src_file == NULL) {
            perror("Eroare la deschiderea unui fișier sursă");
            fclose(dest_file);
            exit(EXIT_FAILURE);
        }

        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
            size_t bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
            if (bytes_written != bytes_read) {
                perror("Eroare la scrierea în fișierul destinație");
                fclose(src_file);
                fclose(dest_file);
                exit(EXIT_FAILURE);
            }
        }

        fclose(src_file);
    }

    fclose(dest_file);
}

int main(int argc, char *argv[])
{
    int m, n;

    scanf("%d", &m);
    scanf("%d", &n);

    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    FILE *fout = fopen("matrice.bin", "wb");
    if (fout == NULL) {
        perror("Eroare la deschiderea fișierului pentru scriere");
        return 1;
    }
    fwrite(&m, sizeof(int), 1, fout);
    fwrite(&n, sizeof(int), 1, fout);
    for (int i = 0; i < m; i++) {
        fwrite(a[i], sizeof(int), n, fout);
    }
    fclose(fout);

    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    FILE *fin = fopen("matrice.bin", "rb");
    if (fin == NULL) {
        perror("Eroare la deschiderea fișierului pentru citire");
        return 1;
    }
    fread(&m, sizeof(int), 1, fin);
    fread(&n, sizeof(int), 1, fin);

    int **b = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        fread(b[i], sizeof(int), n, fin);
    }
    fclose(fin);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(b[i]);
    }
    free(b);


    if (argc != 2) {
        fprintf(stderr, "Utilizare: %s <nume_fișier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_hexdump(argv[1]);

    if (argc < 3) {
        fprintf(stderr, "Utilizare: %s <fișier1> <fișier2> ... <fișier_destinație>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    concatenate_files(argc - 1, argv + 1);
    return 0;
}

