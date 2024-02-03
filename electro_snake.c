#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

// Input function to read the matrix from stdin
void input(int ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    *matrix = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            scanf("%d", &((*matrix)[i][j]));
        }
    }
}

// Output function to print the matrix to stdout
void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Sort function to sort the matrix in vertical zigzag pattern
void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (matrix[i][j] > matrix[k][j]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
    // Copy sorted matrix to result_matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[i][j] = matrix[i][j];
        }
    }
}
// Sort function to sort the matrix in horizontal zigzag pattern
void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
    // Copy sorted matrix to result_matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[i][j] = matrix[i][j];
        }
    }
}
// Main function to drive the program
int main() {
    int **matrix, **result;
    int n, m;

    input(&matrix, &n, &m);

    result = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        result[i] = malloc(m * sizeof(int));
    }

    sort_vertical(matrix, n, m, result);
    output(result, n, m);
    printf("\n");

    sort_horizontal(matrix, n, m, result);
    output(result, n, m);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}
