#include <stdio.h>
#define N 4
#define P 3


int *a[P];
int boolfunc(int *var, int m);
int recursivebool(int *var, int n);
void combinations(int A[], int n, int k);

int main()
{
    int A[] = {4, 1, 2, 3, 4};
    int varbool[20];
    
    recursivebool(varbool, N);
    combinations(A, 5, 3);
    
    return 0;
}

int boolfunc(int *var, int m)
{
    int result=var[0], i;
    
    for(i=1; i<m; i++) 
        result = (result && var[i]);
        
    return result;
}

int recursivebool(int *var, int n)
{
    int localvar[20], i, j;
    
    if(n == 0)
        {
            for(i=0; i<N; i++) printf("%d ", var[i]);
                printf("%d\n", boolfunc(var, N));
            return 1;
        }
        
    for(j=0; j<=1; j++)
        {
            var[n-1] = j;
            recursivebool(var, n - 1);
        }
}

void combinations(int A[], int n, int k)
{
    int i, j, m = 123;
    
    if(k == 0)
        {
            for(i = P; i >= 2; i--)
                if(a[i - 1] <= a[i - 2] || *a[i - 1] <= *a[i - 2]) m = 0;
            if(m == 123)
            {
                for(i = 0; i < P; i++)
                    printf("%d ", *a[i]);
                    
                printf("\n");
            }
            return;
        }
    for(j = 0; j < n; j++)
    {
        a[k - 1] = &A[j];
        combinations(A, n, k - 1);
    }
    return;
}
