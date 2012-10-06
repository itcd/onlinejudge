#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 64;
const int MAXLEN = 101;
const int d = 8;
int m, n;
char map[MAX][MAX];
char s[MAXLEN];
int len;
int memo[MAX][MAX][MAXLEN];
int dr[d] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[d] = {0, 0, -1, 1, -1, -1, 1, 1};

int zan[MAXLEN * d];

int count(int x,int y, int step)
{
	int totalcount = 0;

	step++;

	//对每个方向
	for(int k = 0;k < d;k++)
	{
		//如果在边界里面
		int nexti = y + dr[k];
		int nextj = x + dc[k];
		if((nexti >= 0) && (nexti < m) && (nextj >= 0) && (nextj < n))
		{
			if(map[nexti][nextj] == s[step - 1])
			{
				if(step == len)
				{
					totalcount += 1;
				}

				if(memo[nexti][nextj][step] != -1)
				{
					totalcount += memo[nexti][nextj][step];
				}
				else
				{
					totalcount += count(nextj, nexti, step);
				}
			}
		}
	}

	step--;
	memo[y][x][step] = totalcount;

	return totalcount;
}

void main()
{


	int times, i, j, total = 0;
	scanf("%d", &times);
	while(times>0)
	{
		times--;
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++)
			scanf("%s", map[i]);
		scanf("%s", s);
		len = strlen(s);

		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < m;j++)
			{
				for(int k = 0;k < len;k++)
				{
					memo[i][j][k] = -1;
				}
			}
		}

		total = 0;

		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(map[i][j] == s[0])
				{
					total += count(j,i,1);
				}
			}
		}


		printf("%d\n", total);
	}
}