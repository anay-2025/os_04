#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 10

// Function to calculate determinant recursively
double determinant(double mat[MAX][MAX], int n) {
    double det = 0;
    double submat[MAX][MAX];

    if (n == 1)
        return mat[0][0];

    int sign = 1;

    for (int x = 0; x < n; x++) {
        int subi = 0;

        for (int i = 1; i < n; i++) {
            int subj = 0;

            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;

                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }

        det += sign * mat[0][x] * determinant(submat, n - 1);
        sign = -sign;
    }

    return det;
}

// Replace a column with constants vector
void replace_column(double dest[MAX][MAX], double src[MAX][MAX], double B[], int n, int col) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];

    for (int i = 0; i < n; i++)
        dest[i][col] = B[i];
}

int main() {

    int n;
    double A[MAX][MAX], B[MAX];

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter coefficient matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter constants vector:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i]);

    double D = determinant(A, n);

    if (D == 0) {
        printf("System has no unique solution\n");
        return 0;
    }

    printf("Main Determinant (D) = %lf\n", D);

    for (int i = 0; i < n; i++) {

        pid_t pid = fork();

        if (pid == 0) {   // Child process

            double temp[MAX][MAX];
            replace_column(temp, A, B, n, i);

            double Di = determinant(temp, n);
            double Xi = Di / D;

            printf("X%d = %lf (Process ID: %d)\n", i + 1, Xi, getpid());

            exit(0);
        }
    }

    // Parent waits for all child processes
    for (int i = 0; i < n; i++)
        wait(NULL);

    return 0;
}