//GREEDY
#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
    int visited;
} Point;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int findNearestPoint(Point points[], int n, Point current) {
    int nearestIndex = -1;
    double minDistance = DBL_MAX;

    for (int i = 0; i < n; i++) {
        if (!points[i].visited) {
            double dist = distance(current, points[i]);
            if (dist < minDistance) {
                minDistance = dist;
                nearestIndex = i;
            }
        }
    }

    return nearestIndex;
}

int main() {
    int n;
    printf("Introduceți numărul de puncte (n < 100): ");
    scanf("%d", &n);

    Point points[MAX_POINTS];
    for (int i = 0; i < n; i++) {
        printf("Introduceți coordonatele punctului %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
        points[i].visited = 0;
    }

    Point current = {0, 0};
    for (int i = 0; i < n; i++) {
        int nearestIndex = findNearestPoint(points, n, current);
        if (nearestIndex != -1) {
            points[nearestIndex].visited = 1;
            current = points[nearestIndex];
            printf("Gaura %d: (%lf, %lf)\n", i + 1, current.x, current.y);
        }
    }

    return 0;
}
//-----------------------------------
//DIVIDE ET IMPERA
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double position;
    double force;
} ForceResult;

ForceResult calculateForce(double ma, double mb, double m, double d, double x) {
    ForceResult result;
    double dist_ma = x;
    double dist_mb = d - x;

    double force_ma = G * ma * m / (dist_ma * dist_ma);
    double force_mb = G * mb * m / (dist_mb * dist_mb);

    result.position = x;
    result.force = force_mb - force_ma;

    return result;
}

void divideEtImpera(double ma, double mb, double m, double d, int n, int start, int end, ForceResult results[]) {
    if (start > end) {
        return;
    }

    if (start == end) {
        double x = (double)start * d / n;
        results[start] = calculateForce(ma, mb, m, d, x);
        return;
    }

    int mid = (start + end) / 2;
    divideEtImpera(ma, mb, m, d, n, start, mid, results);
    divideEtImpera(ma, mb, m, d, n, mid + 1, end, results);
}

int main() {
    int n;
    double ma, mb, m, d;

    printf("Introduceți numărul de pași n: ");
    scanf("%d", &n);
    printf("Introduceți masa corpului ma (kg): ");
    scanf("%lf", &ma);
    printf("Introduceți masa corpului mb (kg): ");
    scanf("%lf", &mb);
    printf("Introduceți masa corpului mobil m (kg): ");
    scanf("%lf", &m);
    printf("Introduceți distanța d (m): ");
    scanf("%lf", &d);

    ForceResult results[n + 1];
    divideEtImpera(ma, mb, m, d, n, 0, n, results);

    for (int i = 0; i <= n; i++) {
        printf("Pasul %d: Poziția = %lf, Forța F = %e N\n", i, results[i].position, results[i].force);
    }

    return 0;
}
//----------------------------
//DIVIDE ET IMPERA
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if(a>b)
        return b;
    else
        return a;
}

int reduceMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol) {
    if (startRow > endRow || startCol > endCol) {
        return 0;
    }

    if (startRow == endRow && startCol == endCol) {
        return matrix[startRow][startCol];
    }

    int midRow = (startRow + endRow) / 2;
    int midCol = (startCol + endCol) / 2;

    int topLeft = reduceMatrix(matrix, startRow, midRow, startCol, midCol);
    int topRight = reduceMatrix(matrix, startRow, midRow, midCol + 1, endCol);
    int bottomLeft = reduceMatrix(matrix, midRow + 1, endRow, startCol, midCol);
    int bottomRight = reduceMatrix(matrix, midRow + 1, endRow, midCol + 1, endCol);

    int topMax = max(topLeft, topRight);
    int bottomMin = min(bottomLeft, bottomRight);

    return topMax - bottomMin;
}

int main() {
    int m, n;
    printf("Introduceți dimensiunile matricei (m și n): ");
    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Introduceți elementele matricei:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int reduction = reduceMatrix(matrix, 0, m - 1, 0, n - 1);
    printf("Reducerea matricei este: %d\n", reduction);

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
