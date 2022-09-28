#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float x = atof (argv[1]);
    float i;
    
    i = 3 * x * x * x * x * x 
        + 2 * x * x * x * x 
        - 5 * x * x * x 
        - x * x 
        + 7 * x 
        - 6;
        
    printf("the answer is : %.2f\n", i);

    return 0;
}