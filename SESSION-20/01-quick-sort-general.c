#include <stdio.h> 

#define _CRT_RAND_S
#include <stdlib.h> 
#include <time.h>

#define TRUE    1 

typedef long long int s_size_t; 

//  Interface functions 
void input_array(int* a, s_size_t N); 
void output_array(int* a, s_size_t N, const char* msg); 
void sort(int* a, s_size_t N); 

//  Actual sorting functions 
void quick_sort(int* a, s_size_t p, s_size_t r); 
s_size_t partition(int* a, s_size_t p, s_size_t r); 

//  Helper function 
void* xmalloc(s_size_t size); 

int main(int argc, char* argv[])
{
    time_t t_start, t_end, t_delta; 
    if(argc != 2)
    {
        fprintf(stderr, "Usage Error: %s number_of_elements\n", argv[0]); 
        exit(EXIT_FAILURE); 
    }

    s_size_t N = atoll(argv[1]); 
    int* a = (int*)xmalloc(N * sizeof(int)); 

    input_array(a, N); 
    //output_array(a, N, "Before sort:"); 
    t_start = time(0);
    sort(a, N); 
    t_end = time(0); 
    //output_array(a, N, "After sort:");

    t_delta = t_end - t_start; 
    printf("Physical Time Required:%ld\n", t_delta); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
}


//  Interface functions 
void input_array(int* a, s_size_t N)
{
    unsigned int num; 

    for(s_size_t i = 0; i < N; ++i)
    {
        rand_r(&num); 
        a[i] = num; 
    }
}

void output_array(int* a, s_size_t N, const char* msg)
{
    if(msg)
        puts(msg); 

    for(s_size_t i = 0; i < N; ++i)
        printf("a[%llu]:%d\n", i, a[i]); 
}

void sort(int* a, s_size_t N)
{
    quick_sort(a, 0, N-1); 
} 

//  Actual sorting functions 
void quick_sort(int* a, s_size_t p, s_size_t r)
{
    //printf("p = %llu, r = %llu\n", p, r); 
    if(p < r)
    {
        s_size_t q = partition(a, p, r);
        //printf("q = %llu\n", q); 
        quick_sort(a, p, q-1); 
        quick_sort(a, q+1, r); 
    }
}

s_size_t partition(int* a, s_size_t p, s_size_t r)
{
    s_size_t i, j; 
    int pivot, tmp; 

    pivot = a[r]; 
    i = p - 1; 
    for(j = p; j < r; ++j)
    {
        if(a[j] < pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}

//  Helper function 
void* xmalloc(s_size_t size)
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
