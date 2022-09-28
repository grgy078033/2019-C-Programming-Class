#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmax 30

int mine(int **map, int i, int j,int N);

int main(int argc, char *argv[])
{
    system("clear");
    srand(time(NULL));
    int bomb, i, j, m, n, x;
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

    int **map, *a1[N], a2[N][N];
    map = (int **) a1;
    for (i = 0; i < N; i++)
        map[i] = (int *)a2[i];

    while(bomb < M)
    {
        i = rand()%N;
        j = rand()%N;
        if(map[i][j] == 9)
            continue;
        map[i][j] = 9;
        bomb++;
    }

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            if(map[i][j] == 9)
                continue;
            else
                map[i][j] = 10;
        }

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            printf("? ");
            if(j == N - 1)
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

        if(map[i][j] != 9 && map[i][j] != 10)
        {
            printf("you have guessed this position.\nchoose another.\n");
            continue;
        }

        if(map[i][j] == 9)
        {
            printf("You Are Dead!!\n\n");
            break;
        }

        mine(map, i, j, N);

        x = 0;

        for(m = 0; m < N;  m++)
        {
            for(n = 0; n < N; n++)
            {
                if(map[m][n] != 10 && map[m][n] != 9)
                {
                    if(map[m][n] == 0)
                        printf("_ ");
                    else
                        printf("%d ", map[m][n]);
                }
                else
                {
                    x++;
                    printf("? ");
                }
            }
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


