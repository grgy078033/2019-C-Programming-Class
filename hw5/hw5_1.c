#include <stdio.h>

int f_a(int i)
{
  if(i < 3) return i;
  return f_a(i - 1) + f_a(i - 2) + f_a(i - 3);
}

int f_b(int i)
{
  int n = 2;
  int arr[100] = {0, 1, 2};
  if (i <= n) return i;
  for(int j = n + 1; j <= i; j++)
   {
     arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
     n++;
   }
  return arr[i];
}

int f_c(int i)
{
  static int n = 2;
  static int arr[100] = {0, 1, 2};
  if(i <= n) return arr[i];
  arr[i] = f_c(i - 1) + f_c(i - 2) + f_c(i - 3);
  n++;
  return arr[i];
}

int main()
{
  printf("%d\n", f_a(5));
  printf("%d\n", f_b(5));
  printf("%d\n", f_c(5));
  return 0;
}
