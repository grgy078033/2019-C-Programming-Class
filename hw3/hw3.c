#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    int main(int argc, char *argv[])
{ 
    system("clear");
    int i, l, m;
    int j = 0;
    int k = 0;
    int N = atof(argv[1]); /*數字範圍*/
    int P = atof(argv[2]); /*多少個數字*/
    int *a = malloc(P * sizeof(int));
    int *b = malloc(P * sizeof(int));
    srand(time(NULL));

      for(i = 0; i < P; i++){
        a[i] = rand()%N + 1;
    }

    while(b != a){
      printf("Guess: ");
      for(i = 0; i < P; i++){
        scanf("%d", &b[i]);
      }

      for(l = 0; l < P; l++){
        if(b[l] == a[l])
          j++;}
      for(l = 0; l < P; l++){
        if(b[l] != a[l]){
            for(m = 0; m < P; m++){
              if(a[m] == b[l])
              {
                k++;
                break;
              }
            }
        }
      }

      if(j == P){
        break;
      }
      else{
            printf("%dH%dX\n", j, k);
            j -= j;
            k -= k;
          }
    }
    printf("Correct\n");

    return 0;
}
