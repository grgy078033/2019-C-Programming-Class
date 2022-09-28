#include <stdio.h>
#include <stdlib.h>

float horner(int A[], int n, float x) /* 將horner宣告成浮點數 */
{                                      
    int i;
    float result;
    
    result = A[n-1];
    for(i = 1; i <= n-1; i++)
    {
        result = result * x + A[n-1-i];
    }

    return result;
}

int main(int argc, char *argv[])
{
  float z;
  float y = atof(argv[1]);
  int B[6] = {-6, 7, -1, -5, 2, 3};
  z = horner(B, 6, y);
  printf("the answer is : %.2f\n", z);
  
  return 0;
}