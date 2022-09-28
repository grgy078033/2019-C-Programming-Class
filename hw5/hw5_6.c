#include <stdio.h>

int determinant(int f[][10], int x)
{
  int pr = 1, c[10], d = 0, b[10][10], j, p, q, t;
  if(x == 2) return(f[1][1] * f[2][2] - f[1][2] * f[2][1]);

  for(j = 1; j <= x; j++){
      int r = 1, s = 1;
      for(p = 1; p <= x; p++){
        for(q = 1; q <= x; q++){
          if(p != 1 && q != j){
            b[r][s] = f[p][q];
            s++;
            if(s > x - 1){r++; s = 1;}
          }
        }
      }
      pr = j % 2? 1 : -1;
      c[j] = pr * determinant(b , x - 1);
    }
    for(j = 1, d = 0; j <= x; j++) d += (f[1][j] * c[j]);
    return(d);
}

int main()
{
  int a[][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 1, 2, 2, 0, 0, 0, 0, 0, 0},
                 {0, 3, 2, 2, 0, 0, 0, 0, 0, 0},
                 {0, 5, 6, 8, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},};
  int x = determinant(a, 3);
  printf("%d\n", x);
  return 0;
}
