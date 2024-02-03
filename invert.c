#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void invert(double **matrix, int n, int m);
void input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);
double det(double **matrix, int n, int m);
double transp(double **matrix, int n, int m, double *det);

int main() {
    double **matrix;
    int n, m;
    input(&matrix, &n, &m);
    double deter = det(matrix, n, m);
    transp(matrix, n, m, &deter);

    return 0;
}

void input(double ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    *matrix = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            scanf("%lf", &((*matrix)[i][j]));
        }
    }
}

double det(double **matrix, int n, int m) {
    int i, j, k;
    double t, det;
    for (k = 0; k < n; k++) {
        for (i = k + 1; i < m; i++) {
            t = -matrix[i][k] / matrix[k][k];

            for (j = k + 1; j < n; j++) {
                matrix[i][j] += t * matrix[k][j];
            }
        }
    }
    det = 1.0;
    for (k = 0; k < n; k++) {
        det = det * matrix[k][k];
    }
    printf("det = %lf", det);
    return det;
}

double transp(double **matrix, int n, int m, double *det) {
    int i, j;

    double result[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        printf("\n ");
        for (j = 0; j < 3; j++) {
            printf("%lf ", (1 / *det) * result[i][j]);
        }
    }

    printf("\n ");
    return 0;
}
