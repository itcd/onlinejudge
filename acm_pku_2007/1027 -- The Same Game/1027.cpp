#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int W = 5;
const int H = 5;

const char EMPTY = '*';
char ball[H][W+2];
char ch;
int index;
int used[H][W];
int count[H*W+2];

void changeIndex(int r, int c, int &oldIndex, int &newIndex)
{
    if(r<0 || r>=H || c<0 || c>=W)
        return;

    if(used[r][c] == oldIndex)
    {
        used[r][c] = newIndex;
        changeIndex(r+1, c, oldIndex, newIndex);
        changeIndex(r, c-1, oldIndex, newIndex);
    }
}

void findSame(int r, int c)
{
    if(r<0 || r>=H || c<0 || c>=W)
        return;

    if(ball[r][c] == ch)
    { 
        if(used[r][c] > 0)
        {
            if(used[r][c] != index)
            {
                printf("position:%d,%d\tindex:%d,%d\tcount:%d,%d\n", r, c, index, used[r][c], count[index], count[used[r][c]]);
                count[used[r][c]] += count[index];
                changeIndex(r+1, c, index, used[r][c]);
                changeIndex(r, c-1, index, used[r][c]);
                count[index] = 0;
                index--;
            }
        }else
        {
            used[r][c] = index;
            count[index]++;
            findSame(r-1, c);
            findSame(r, c+1);   
        }
    }
}

void downward_leftward()
{
    int i, j, k, m, n;
    char c;

    // downward
    for(j=0; j<W; j++)
    {
        i = H - 1;
        while(i >= 0)
        {
            for(k=i; k>=0; k--)
            {
                if(ball[k][j] != EMPTY)
                    break;
            }
            if(ball[i][j] == EMPTY)
            {
                for(m=k; m>=0; m--)
                {
                    c = ball[m][j];
                    ball[m][j] = ball[m+i-k][j];
                    ball[m+i-k][j] = c;
                }
            }
            i = k - 1;
        }
    }

    // leftward
    j = 0;
    while(j<W)
    {
        for(k=j; k<W; k++)
        {
            if(ball[H-1][k] != EMPTY)
                break;
        }
        if(ball[H-1][j] == EMPTY)
        {
            for(m=k; m<W; m++)
            {
                for(n=0; n<H; n++)
                {
                    c = ball[n][m];
                    ball[n][m] = ball[n][m+j-k];
                    ball[n][m+j-k] = c;
                }
            }
        }
        j = k + 1;
    }
}

int main()
{
    int i, j, max;
    int move = 0;

    for(i=0; i<H; i++)
        gets(ball[i]);

    //puts("");
    //for(i=0; i<H; i++)
    //    puts(ball[i]);

    do
    {
        move++;
        index = 0;
        memset(used, 0, sizeof(bool) * (H * W));
        memset(count, 0, sizeof(int) * (H * W + 2));
        printf("move %d:\n", move);

        for(j=0; j<W; j++)
        {
            for(i=H-1; i>=0; i--)
            {
                ch = ball[i][j];
                if(ch!=EMPTY && used[i][j] == 0)
                {  
                    index++;
                    findSame(i, j);
                }
            }
        }

        for(i=0; i<H; i++)
        {
            for(j=0; j<W; j++)
            {
                printf("(%d,%d)%d:%d", i, j, used[i][j], count[used[i][j]]);
                if(j < W-1)
                    printf("\t");
            }
            printf("\n");
        }

        if(index > 0)
        {
            max = 1;
            for(i=2; i<=index; i++)
            {
                if(count[i] > count[max])
                    max = i;
            }

            for(i=0; i<H; i++)
            {
                for(j=0; j<W; j++)
                {
                    if(used[i][j] == max)
                        ball[i][j] = EMPTY;
                }
            }

            for(i=0; i<H; i++)
                puts(ball[i]);
            printf("max index=%d\tcount=%d\n", max, count[max]);

            downward_leftward();

            for(i=0; i<H; i++)
                puts(ball[i]);
            puts("");
        }
    }while(index>0);

    return 0;
}