#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 3

// Function to compute determinant of 3x3 matrix
float determinant(float m[N][N]) {
    float det;

    det = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
        - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0])
        + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);

    return det;
}

// Function to replace column
void replaceColumn(float temp[N][N], float A[N][N], float B[N], int col) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            temp[i][j] = A[i][j];

    for(int i=0;i<N;i++)
        temp[i][col] = B[i];
}

int main() {

    float A[N][N];
    float B[N];

    printf("Enter coefficient matrix (3x3):\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%f",&A[i][j]);

    printf("Enter constants vector:\n");
    for(int i=0;i<N;i++)
        scanf("%f",&B[i]);

    float D = determinant(A);

    if(D == 0) {
        printf("No unique solution\n");
        return 0;
    }

    for(int i=0;i<N;i++) {

        pid_t pid = fork();

        if(pid == 0) { // child process

            float temp[N][N];
            replaceColumn(temp, A, B, i);

            float Di = determinant(temp);

            float Xi = Di / D;

            printf("Solution X%d = %f\n", i+1, Xi);

            return 0;
        }
    }

    // parent waits for all children
    for(int i=0;i<N;i++)
        wait(NULL);

    return 0;
}