void PrintBit(int a, int b, int c, int d)
{
    unsigned n, n1;
    int i;
    
    n1 = (((n << 8 | a) << 8 | b) << 8 | c) << 8 | d;
    
    unsigned ip = *(int*)&n1;
    unsigned mask = 0x80000000;
    for(i = 0; i < 32; i++)
      {
        if(i == 8 || i == 16 || i == 24)
          printf(" ");
        printf("%d", ((ip&mask)>>(31 - i)));
        mask >>= 1;
     }
}
int main()
{
    PrintBit(129, 160, 96, 1);
    return 0;
}
-------------------------------------------------
void PrintIP(char n[])
{
 int i;
 unsigned mask = 0xff;
 unsigned n1 = 0;
    for(i = 0; i <= 31; i++)
      {
        if(n[i] == '0')
          n1 = (n1 | 0);
        if(n[i] == '1')
          n1 = (n1 | 1);
        if(i == 31)
          break;
        n1 <<= 1;
      }
      
 unsigned a = (n1 >> 24) & mask;
 unsigned b = (n1 >> 16) & mask;
 unsigned c = (n1 >> 8) & mask;
 unsigned d = n1 & mask;
 
 printf("%d.", a);
 printf("%d.", b);
 printf("%d.", c);
 printf("%d", d);
 
}

int main()
{
    char n[] = "10000001101000000110000000000001";
    PrintIP(n);
    return 0;
}






mix version
--------------------------------------------------------
#include <stdio.h>

void PrintBit(int a, int b, int c, int d)
{
    unsigned n, n1;
    int i;
    
    n1 = (((n << 8 | a) << 8 | b) << 8 | c) << 8 | d;
    
    unsigned ip = *(int*)&n1;
    unsigned mask = 0x80000000;
    for(i = 0; i < 32; i++)
      {
        if(i == 8 || i == 16 || i == 24)
          printf(" ");
        printf("%d", ((ip&mask)>>(31 - i)));
        mask >>= 1;
     }
}

void PrintIP(char n[])
{
 int i;
 unsigned mask = 0xff;
 unsigned n1 = 0;
    for(i = 0; i <= 31; i++)
      {
        if(n[i] == '0')
          n1 = (n1 | 0);
        if(n[i] == '1')
          n1 = (n1 | 1);
        if(i == 31)
          break;
        n1 <<= 1;
      }
      
 unsigned a = (n1 >> 24) & mask;
 unsigned b = (n1 >> 16) & mask;
 unsigned c = (n1 >> 8) & mask;
 unsigned d = n1 & mask;
 
 printf("%d.", a);
 printf("%d.", b);
 printf("%d.", c);
 printf("%d\n", d);
 
}

int main()
{
    PrintBit(129, 160, 96, 1);
    printf("\n");
    char n[] = "10000001101000000110000000000001";
    PrintIP(n);
    return 0;
}