#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
     double x;
     double z;
     int a;
     double i;
     double n = atof(argv[1]);

     for(i = 1; i <= n; i++)
  {
       z = 1.0f / i;
       x = (1 + z);
     if(i == 1)
       printf("%.10f\n", x);
     else
    {
       double y = 1;
         for(a = 1; a <= i; a++)
           y = y * x;
     printf("%.10f\n", y);
    }
}
return 0;
}