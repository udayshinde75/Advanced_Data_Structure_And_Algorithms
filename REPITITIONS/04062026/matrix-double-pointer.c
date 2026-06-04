#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;

struct Matrix {
    int** data;
    int rows;
    int cols;
};

// Create Matrix
Matrix* create_matrix(int rows, int cols)
{
    Matrix* M;
    M->rows = rows;
    M->cols = cols;

    M->data = (int**)malloc(sizeof(int*) * M->rows);

    if (M->data == NULL)
    {
        fprintf(stderr, "FATAL : MALLAC : Out of memory");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < M->rows; ++i)
    {
        M->data[i] = (int*)malloc(M->cols * sizeof(int));

        if (M->data[i] == NULL)
        {
            fprintf(stderr, "FATAL : MALLAC : Out of memory");
            exit(EXIT_FAILURE);
        }   
    }

    return (M);
}

// Fill matrix value
void fill_matrix(Matrix* m, int value)
{
    for (size_t i = 0; i < m->rows; ++i)
    {
        for (size_t j = 0; j < m->cols; ++j)
        {
            m->data[i][j] = value;
        }   
    }
}

// Unit matrix
void make_matrix_unit(Matrix* m)
{
    for (size_t i = 0; i < m->rows; ++i)
    {
        for (size_t j = 0; j < m->cols; ++j)
        {
            if (i == j)
            {
                m->data[i][j] = 1;
            }
            else
            {
                m->data[i][j] = 0;
            }
        }   
    }
}

// Print matrix
void print_matrix(Matrix* m)
{
    for (size_t i = 0; i < m->rows; ++i)
    {
        for (size_t j = 0; j < m->cols; ++j)
        {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Resize matrix
void resize_matrix(Matrix* m, int new_rows, int new_columns)
{
    m->data = (int**)malloc(new_rows * sizeof(int*));

    if (condition)
    {
        /* code */
    }
    
}