#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void input(double ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    *matrix = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            scanf("%le", &((*matrix)[i][j]));
        }
    }
}

void output(double det) { printf("%lf", det); }

double det(double **matrix, int n, int m) {
    int i, j, k;
    double t, det;
    for (k = 0; k < n; k++) {
        for (i = k + 1; i < m; i++) {
            t = matrix[i][k] / matrix[k][k];
            matrix[i][k] = 0;
            for (j = k + 1; j < n; j++) {
                matrix[i][j] = matrix[i][j] - t * matrix[k][j];
            }
        }
    }
    det = 1.0;
    for (k = 0; k < n; k++) {
        det = det * matrix[k][k];
    }
    return det;
}

int main() {
    double **matrix;
    int n, m;
    input(&matrix, &n, &m);

    if (det(matrix, n, m) >= 0) {
        output(fabs(det(matrix, n, m)));
    } else {
        output((det(matrix, n, m)));
    };
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
