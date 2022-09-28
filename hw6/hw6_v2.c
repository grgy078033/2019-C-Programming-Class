#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 30

int mine(int **map, int i, int j, int N);

int main(int argc, char *argv[])
{
    system("clear");
    srand(time(NULL));
    int bomb = 0, i, j, m, n, x, y;
    int game = 1;
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    while(N > Nmax || N <= 0)
    {
        printf("your N should lower or equal 30 and bigger than 0\n");
        printf("input a new N:\n");
        scanf("%d", &N);
        printf("\n");
    }

    int *a1, a2[N][N], *a3[N], **map;
    a1 = (int *)a2;
    map = (int **)a3;
    for(i = 0; i < N; i++)
        map[i] = (int *)a2[i];
    
    for(a1 = &a2[0][0]; bomb < M; a1++)
    {
        i = rand()%N;
        j = rand()%N;
        if(*(*(a2+i)+j) == 9)
            continue;
        *(*(a2+i)+j) = 9;
        bomb++;
    }

    for(a1 = &a2[0][0]; a1 <= &a2[N - 1][N - 1]; a1++)
        {
            if(*a1 == 9)
                continue;
            else
                *a1 = 10;
        }

    for(y = N + 2, a1 = &a2[0][0]; a1 <= &a2[N - 1][N - 1]; a1++, y++)
        {
            printf("? ");
            if(y != N + 2 && y % N == 1)
                printf("\n");
        }

    while(game)
    {
        int k = 0;
        printf("\nguess:");
        scanf("%d%d", &i, &j);
        printf("\n");

        if(i < 0 || i > N || j < 0 || i > N)
        {
            printf("wrong position.\nchoose another.\n");
            continue;
        }

        if(*(*(a2+i)+j) != 9 && *(*(a2+i)+j) != 10)
        {
            printf("you have guessed this position.\nchoose another.\n");
            continue;
        }

        if(*(*(a2+i)+j) == 9)
        {
            printf("You Are Dead!!\n\n");
            break;
        }

        mine(map, i, j, N);

        x = 0;

        for(y = N + 2, a1 = &a2[0][0]; a1 <= &a2[N - 1][N - 1]; a1++, y++)
        {
            if(*a1 != 10 && *a1 != 9)
            {
                if(*a1 == 0)
                    printf("_ ");
                else
                    printf("%d ", *a1);
            }
            else
            {
                x++;
                printf("? ");
            }
            if(y != N + 2 && y % N == 1)
                printf("\n");
        }
        
        if(x * 9 == M * 9)
        {
            printf("\nYou Win!!\n\n");
            break;
        }

    }
    return 0;
}

int mine(int **map, int i, int j, int N)
{
    int m, n, k = 0, p, q;

    if(map[i][j] == 9 || map[i][j] == 10)
    {
        for(m = i - 1; m <= i + 1; m++)
        {
            for(n = j - 1; n <= j + 1; n++)
            {
                if(m == i && n == j)
                    continue;
                if(m < 0 || m >= N)
                    continue;
                if(n < 0 || n >= N)
                    continue;
                if(map[m][n] == 9)
                    k++;
            }
            if(m == i + 1)
            {
                map[i][j] = k;

                if(map[i][j] == 0)
                {
                    for(p = i - 1; p <= i + 1; p++)
                        for(q = j - 1; q <= j + 1; q++)
                        {
                            if(p == i && q == j)
                                continue;
                            if(p < 0 || p >= N)
                                continue;
                            if(q < 0 || q >= N)
                                continue;
                            mine(map, p, q, N);
                        }
                }
                else
                    return map[i][j];
            }
        }
    }
    else
        return map[i][j];
}

