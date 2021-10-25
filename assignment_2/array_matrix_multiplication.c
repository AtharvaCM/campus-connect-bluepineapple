// Program to multiply two matrices
// Number of cols in matrix-1 should be equal to number of rows in matrix-2

#include <stdio.h>
#include <stdlib.h>

int ROW_COUNT_1 = 0;
int COL_COUNT_1 = 0;
int ROW_COUNT_2 = 0;
int COL_COUNT_2 = 0;

void get_matrix_dimensions()
{
    printf("\n[+] Enter number of ROWS for matrix 1: ");
    scanf("%d", &ROW_COUNT_1);
    printf("\n[+] Enter number of COLS for matrix 1: ");
    scanf("%d", &COL_COUNT_1);
    printf("\n[+] Enter number of ROWS for matrix 2: ");
    scanf("%d", &ROW_COUNT_2);
    printf("\n[+] Enter number of COLS for matrix 2: ");
    scanf("%d", &COL_COUNT_2);
}

int main()
{
    get_matrix_dimensions();

    // decalre the matrices
    int matrix1[ROW_COUNT_1][COL_COUNT_1];
    int matrix2[ROW_COUNT_2][COL_COUNT_2];

    // input the values for matrix 1
    printf("\n[+] Enter values for matrix 1:\n");
    for (int i = 0; i < ROW_COUNT_1; i++)
    {
        for (int j = 0; j < COL_COUNT_1; j++)
        {
            printf("\t[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // input the values for matrix2
    printf("\n[+] Enter values for matrix 2:\n");
    for (int i = 0; i < ROW_COUNT_2; i++)
    {
        for (int j = 0; j < COL_COUNT_2; j++)
        {
            printf("\t[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // print matrix
    printf("\n");
    for (int i = 0; i < ROW_COUNT_1; i++)
    {
        for (int j = 0; j < COL_COUNT_1; j++)
            printf("\t%d", matrix1[i][j]);
        printf("\n");
    }

    return 0;
}