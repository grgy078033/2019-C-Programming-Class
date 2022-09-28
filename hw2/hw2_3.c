#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int j;
    double n = atof(argv[1]); 
    for(i = 1; i <= n; i++) {
       if(i == 1)
    {
       double x = 2;
       printf("%.10f\n", x);
    }
       else
    {
        double x = 1;
        double a = 0;
          for(j = 1; j <= i; j++)
        {
            x *= j;
            a += 1.0f / x;
        }
        double z = 1 + a;
        printf("%.10f\n", z);
    }
    }
    return 0;
}