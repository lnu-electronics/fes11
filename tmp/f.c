#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    float tmpx, tmpy, *x, *y;
    unsigned count = 0;

    f = fopen("data.txt", "rt");

    while (!feof(f))
    {
        fscanf(f, "%f%f", &tmpx, &tmpy);
        ++count;
    }
    --count;
    x = (float*)malloc(count*sizeof(float));
    y = (float*)malloc(count*sizeof(float));

    fclose(f);
    f = fopen("data.txt", "rt");

    for (int i = 0; i < count; ++i)
    {
        fscanf(f, "%f%f", &x[i], &y[i]);
    }

    for (int i = 0; i < count; ++i)
    {
        printf("%f %f\n", x[i], y[i]);
    }
    

    fclose(f);
    free(x);
    free(y);

    return 0;
}