#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROW 10
#define COL 3

int discs[ROW][COL] = { 0 };

void show(int d[ROW][COL])
{
    printf("%5c%5c%5c\n", 'A', 'B', 'C');
    printf("------------------------\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (d[i][j] == 0)
            {
                printf("%5c", '+');
            }
            else
            {
                printf("%5d", d[i][j]);
            }
        }
        putchar('\n');
    }
}

void init(int d[ROW][COL], int n)
{
    for (int i = ROW - 1; i >= 0; i--)
    {
        d[i][0] = n;
        n = n - 1;
        if (n == 0) break;
    }
}

void move(char polar1, char polar2)
{
    int polar1Col = polar1 - 'A', polar2Col = polar2 - 'A';
    int isrc=0, jsrc=0, idst=0, jdst=0;
    printf("\n> %3c%5s%4c\n", polar1, "   -->", polar2);
    //find the src number
    for (int i = 0; i < ROW; i++)
    {
        if (discs[i][polar1Col] != 0)
        {
            isrc = i;
            jsrc = polar1Col;
            break;
        }
    }

    for (int i = ROW - 1; i >= 0; i--)
    {
        if (discs[i][polar2Col] == 0)
        {
            idst = i;
            jdst = polar2Col;
            break;
        }
    }

    printf("\n");
    int temp;
    temp = discs[isrc][jsrc];
    discs[isrc][jsrc] = discs[idst][jdst];
    discs[idst][jdst] = temp;
    show(discs);
}

void hanoi(int n, char polarA, char polarB, char polarC)
{
    if (n == 1)
    {
        move(polarA, polarC);
    }
    else
    {
        hanoi(n - 1, polarA, polarC, polarB);
        move(polarA, polarC);
        hanoi(n - 1, polarB, polarA, polarC);
    }
}

int main()
{
    int discs_num = 0;
    printf("Please input the number of discs: ");
    scanf("%d", &discs_num);
    init(discs, discs_num);
    show(discs);
    hanoi(discs_num, 'A', 'B', 'C');
    getchar();
    getchar();
}
