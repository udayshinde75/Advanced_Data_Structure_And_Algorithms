#include <stdio.h> 

#define _CRT_RAND_S
#include <stdlib.h> 
#include <time.h>

#define TRUE    1 

//  Interface functions 
void input_array(int* a, size_t N); 
void output_array(int* a, size_t N, const char* msg); 
void sort(int* a, size_t N); 

//  Actual sorting functions 
void merge_sort(int* a, size_t p, size_t r); 
void merge(int* a, size_t p, size_t q, size_t r); 

//  Helper function 
void* xmalloc(size_t size); 

int main(int argc, char* argv[])
{
    time_t t_start, t_end, t_delta; 
    if(argc != 2)
    {
        fprintf(stderr, "Usage Error: %s number_of_elements\n", argv[0]); 
        exit(EXIT_FAILURE); 
    }

    size_t N = atoll(argv[1]); 
    int* a = (int*)xmalloc(N * sizeof(int)); 

    input_array(a, N); 
    //output_array(a, N, "Before sort:"); 
    t_start = time(0);
    sort(a, N); 
    t_end = time(0); 
    //output_array(a, N, "After sort:");

    t_delta = t_end - t_start; 
    printf("Physical Time Required:%lld\n", t_delta); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
}


//  Interface functions 
void input_array(int* a, size_t N)
{
    unsigned int num; 

    for(size_t i = 0; i < N; ++i)
    {
        rand_r(&num); 
        a[i] = num; 
    }
}

void output_array(int* a, size_t N, const char* msg)
{
    if(msg)
        puts(msg); 

    for(size_t i = 0; i < N; ++i)
        printf("a[%llu]:%d\n", i, a[i]); 
}

void sort(int* a, size_t N)
{
    merge_sort(a, 0, N-1); 
} 

//  Actual sorting functions 
void merge_sort(int* a, size_t p, size_t r)
{
    if(p < r)
    {
        size_t q = (p + r)/2; 
        merge_sort(a, p, q); 
        merge_sort(a, q+1, r); 
        merge(a, p, q, r); 
    }
}

void merge(int* a, size_t p, size_t q, size_t r)
{
    int* a1 = NULL; 
    int* a2 = NULL; 

    size_t N1 = q - p + 1; 
    size_t N2 = r - q; 

    size_t i, j, k; 

    a1 = (int*)xmalloc(N1 * sizeof(int)); 
    a2 = (int*)xmalloc(N2 * sizeof(int)); 

    for(i = 0; i < N1; ++i)
        a1[i] = a[p + i]; 

    for(i = 0; i < N2; ++i)
        a2[i] = a[q + 1 + i]; 

    i = j = k = 0; 

    while(TRUE)
    {
        if(a1[i] <= a2[j])
        {
            a[p + k] = a1[i]; 
            k = k + 1; 
            i = i + 1; 
            if(i == N1)
            {
                while(j < N2)
                {
                    a[p + k] = a2[j]; 
                    k = k + 1; 
                    j = j + 1; 
                }

                break; 
            }
        }
        else 
        {
            a[p + k] = a2[j]; 
            k = k + 1; 
            j = j + 1; 
            if(j == N2)
            {
                while(i < N1)
                {
                    a[p + k] = a1[i]; 
                    k = k + 1; 
                    i = i + 1; 
                }

                break; 
            }
        }
    }

    free(a1);
    a1 = NULL; 

    free(a2); 
    a2 = NULL; 
}

//  Helper function 
void* xmalloc(size_t size)
{
    void* ptr = NULL; 

    ptr = malloc(size);
    if(NULL == ptr)
    {
        fprintf(stderr, "malloc():fatal:allocation error\n"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}
