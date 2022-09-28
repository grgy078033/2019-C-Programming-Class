#include <stdio.h>

int I[][2] = {{3, 19}, {11, 33}, {18, 80}, {80, 100}};
int n1 = (sizeof(I)/sizeof(I[0][0])) / 2;
int n2 = (sizeof(I)/sizeof(I[0][0]));
void Range(int I[][2], int v, int R[][2]);
void T_Set(int I[][2], int T[]);

int main()
{
    int R[n1][2], T[n2];
    
    Range(I, 18, R);
    printf("\n");
    T_Set(I, T);
    printf("\n");
    
    return 0;
}

void Range(int I[][2], int v, int R[][2])
{
    int i, N = 0;
    
    for(i = 0; i < n1; i++)
        if(v >= I[i][0] && v <= I[i][1])
            {
                R[N][0] = I[i][0];
                R[N][1] = I[i][1];
                N++;
            }
    
    printf("{");
    for(i = 0; i < N; i++)
        {
            if(i < N - 1)
                printf("[%d,%d],", R[i][0], R[i][1]);
            else
                printf("[%d,%d]", R[i][0], R[i][1]);
        }
    printf("}");
}

void T_Set(int I[][2], int T[])
{
    int i, j, temp;
    
    for(i = 0, j = 0; i < n2; i = i + 2, j++)
        {
            T[i] = I[j][0] - 1;
            T[i + 1] = I[j][1];
        }
        
    for(i = n2 - 1; i > 0; i--)
    {
        for(j = 0; j <= i - 1; j++)
            {
                if(T[j] > T[j + 1])
                    {
                        temp = T[j];
                        T[j] = T[j + 1];
                        T[j + 1] = temp;
                    }
            }
    }
    
    printf("{");
    for(i = 0; i < n2; i++)
        {
            printf("%d", T[i]);
            if(i < n2 - 1)
                printf(",");
        }
    printf("}");
}