#include <stdio.h>
#include <stdlib.h>

double power(int x, int y)
{
    int i;
    double result = 1.0;

    if(y > 0)
    {
      for(i = 0; i < y; i++)
        result *= x;
    }
    else if(y < 0)
    {
      int z = 0 - y;
      for(i = 0; i < z; i++)
        result /= x;
    }
  return result;
}

int main(int argc, char *argv[])
{
    int z = atoi(argv[1]);

    if(z == 1)
    {
      float x = atof(argv[2]);
      int ip, i;
      ip = *(int*)&x;
      unsigned mask = 0x80000000;

      for(i = 0; i < 32; i++)
      {
        if(i == 0)
        {
          if(x >= 0)
            printf("0 ");
          else
            printf("1 ");
        }
        if(i >= 1 && i < 9)
        {
          printf("%d", ((ip&mask)>>(31 - i)));
          if(i == 8)
            printf(" ");
        }
        if(i >= 9 && i < 32)
        {
          printf("%d", ((ip&mask)>>(31 - i)));
          if(i == 31)
            printf("\n");
        }
        mask >>= 1;
      }
    }

    else if(z == 2)
    {
      double x = atof(argv[2]);
      long long ip;
      int i;
      ip = *(long long*)&x;
      unsigned long long mask = 0x8000000000000000;

      for(i = 0; i < 64; i++)
      {
        if(i == 0)
        {
          if(x >= 0)
            printf("0 ");
          else
            printf("1 ");
        }
        if(i >= 1 && i < 12)
        {
          printf("%lld", ((ip&mask)>>(63 - i)));
          if(i == 11)
            printf(" ");
        }
        if(i >= 12 && i < 64)
        {
          printf("%lld", ((ip&mask)>>(63 - i)));
          if(i == 63)
            printf("\n");
        }
        mask >>= 1;
      }
    }

    else if(z == 3)
    {
      char Signed, exp[8], fraction[23];
      int i, binary_exp = 0;
      float binary_fra = 1.0, answer = 0.0;
      sprintf(&Signed, "%c", argv[2]);
      sprintf(exp, "%8s", argv[3]);
      sprintf(fraction, "%23s", argv[4]);
      int x = atoi(argv[2]);

      for(i = 7;i >= 0; i--)
        binary_exp += ( power(2, 7-i) * (exp[i] - '0') );
      for(i = 0; i < 23; i++)
        binary_fra += ( power(2, -1 * (i+1)  ) * (fraction[i] - '0') );

      answer = power(2, binary_exp - 127) * binary_fra;
      if(x == 0)
      {
        printf("");
        printf("%f\n", answer);
      }
      else if(x == 1)
      {
        printf("-");
        printf("%f\n", answer);
      }
    }

    else if(z == 4)
    {
      char Signed, exp[11], fraction[52];
      int i, binary_exp = 0;
      float binary_fra = 1.0, answer = 0.0;
      sprintf(&Signed, "%c", argv[2]);
      sprintf(exp, "%11s", argv[3]);
      sprintf(fraction, "%52s", argv[4]);
      int x = atoi(argv[2]);

      for(i = 10; i >= 0; i--)
        binary_exp += ( power(2, 10-i) * (exp[i] - '0') );
      for(i = 0; i < 52; i++)
        binary_fra += ( power(2, -1 * (i+1)  ) * (fraction[i] - '0') );

      answer = power(2, binary_exp - 1023) * binary_fra;
      if(x == 0)
      {
        printf("");
        printf("%f\n", answer);
      }
      else if(x == 1)
      {
        printf("-");
        printf("%f\n", answer);
      }
    }
  return 0;
}
