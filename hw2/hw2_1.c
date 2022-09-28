#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double a = atof (argv[1]);
    double x0;
    double x1;
    int i = 0;

    while(x0 != x1)
{
       if(i == 0)
   {
        x1 = 1;
        i++;
   }
      else
   {
        x0 = x1;
        x1 = 0.5 * (x1 + a / x1);
        printf("%.10f\n", x1);
        i++;
      int b = atoi (argv[2]);
      if(i == b + 1)
      break;
   }
}
   return 0;
}