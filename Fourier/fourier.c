#include <stdio.h>
#include <math.h>

const float T = 0.02;
const int K = 10;

float s(float t)
{
    if (t >= 0 && t < T/2)
        return 3;
    if (t >= T/2 && t <= T)
        return 5/T*t + 1;
}

void tab(float a, float b, int n)
{
    FILE *f = fopen("func.txt", "wt");
    float dt = (b - a)/n, t = a;

    for (int i = 0; i < n; ++i)
    {
        t = a + i*dt;
        fprintf(f, "%f %f\n", t, s(t));
    }
    fclose(f);
}
float sm(float t, int K);
void tabm(float a, float b, int n)
{
    FILE *f = fopen("funcm.txt", "wt");
    float dt = (b - a)/n, t = a;

    for (int i = 0; i < n; ++i)
    {
        t = a + i*dt;
        fprintf(f, "%f %f\n", t, sm(t, K));
    }
    fclose(f);
}

void coeffs(int N, int K, float a, float b)
{
    FILE *f = fopen("coeffs.txt", "wt");
    float a0 = 0, ak = 0, bk = 0, h = (b-a)/N, ti;

    for (int i = 0; i < N; ++i)
    {
        ti = a + i*h;
        a0 += s(ti);
    }
   
    fprintf(f, "%f\n", 2*h/T*a0);

    for (int k = 1; k <= K; ++k)
    {
        ak = bk = 0; // <- There was an error here :(
        for (int i = 0; i < N; ++i)
        {
            ti = a + i*h;
            ak += s(ti)*cos(2*M_PI/T*k*ti);
            bk += s(ti)*sin(2*M_PI/T*k*ti);
        }
        fprintf(f, "%f %f\n", 2*h/T*ak, 2*h/T*bk);
    }
    fclose(f);
}

float sm(float t, int K)
{
    FILE *f = fopen("coeffs.txt", "rt");
    float a0, ak, bk, s = 0;

    fscanf(f, "%f", &a0);
    for (int k = 1; k <= K; ++k)
    {
        fscanf(f, "%f%f", &ak, &bk);
        //printf("%f %f\n", ak, bk);
        s += ak*cos(k*2*M_PI/T*t) + bk*sin(k*2*M_PI/T*t);
    }

    s += a0/2;
    fclose(f);
    return s;
}

int main()
{

    tab(0, T, 200);
    coeffs(200, K, 0, T);
    tabm(0, T, 200);
    return 0;
}