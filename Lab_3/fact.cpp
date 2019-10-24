#include <iostream>
#include <fstream>

typedef int datatype ; 

int fact_i(int n)
{
    if (n < 2)
    {
        return 1;
    }
    int prod = 1;
    for (int i = 1; i<=n; ++i)
    {
        prod *= i; // prod = prod*i; 
    }
    return prod;
}

int fact_r(int);

int A(int n, int k)
{
    return fact_r(n)/fact_r(n-k);
}

int fact_r(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fact_r(n-1)*n;
}

void rswap(datatype& x, datatype &y)
{
    datatype tmp;
    tmp = x;
    x = y;
    y = tmp;
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

void GenPerm(datatype *a, int n)
{
    for (int i = n-2; i >= 0; --i)
    {
        if (a[i] < a[i+1])
        {
            bubble(a+i+1, n-i-1);
            for (int j = i+1; j < n; ++j)
            {
                if (a[j] > a[i])
                {
                    rswap(a[j], a[i]);
                    break;
                }
            }
            break;
        }
    } 
}

void print_arr(datatype *a, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << *(a+i) << ' ';

    std::cout << '\n';
}


int main()
{
    int fact, n = 6;
    std::ofstream outf("genperm.txt");

    //fact = fact_r(n);
    //std::cout << fact << '\n';
    //std::cout << A(5,3) << '\n';

    int a[6] = {1,2,3,4,5,6};

    std::cout << 1 << " | ";
    outf << 1 << " | ";
    print_arr(a,n);

    for (int i = 2; i <= fact_r(n); ++i)
    {
        GenPerm(a,n);
        std::cout << i << " | ";
        print_arr(a,n);
    }

    outf.close();

    return 0;
}