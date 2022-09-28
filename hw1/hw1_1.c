#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float r = atof(argv[1]);
    float volume;
    float pi = 3.14;
    volume = 4.0f / 3.0f * pi * r * r * r;
    printf("the volume of the sphere is : %.2f\n", volume);
    
    return 0;
}