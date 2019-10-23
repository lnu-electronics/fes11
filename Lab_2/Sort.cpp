#include "Sort.h"

void swap(datatype *x, datatype *y)
{
    datatype tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void rswap(datatype& x, datatype &y)
{
    datatype tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void print_arr(datatype *a, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << *(a+i) << ' ';

    std::cout << '\n';
}

void bubble(datatype *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (a[j-1] > a[j])
            {
                //swap(&a[j-1],  &a[j]);
                rswap(a[j-1],  a[j]);
            }
        }
    }
}

void ins_sort(datatype *a, int n)
{
    int j;
    for (int i = 1; i < n; ++i)
    {
        datatype tmp = a[i];
        for (j = i; j > 0 && a[j-1] > tmp;--j)
        {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}