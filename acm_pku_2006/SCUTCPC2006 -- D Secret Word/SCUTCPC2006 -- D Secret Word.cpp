#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX = 1000000000;
const int MAXARRAY = 64;
const int MAXLEN = 128;
const int d = 8;
int m, n;
char map[MAXARRAY][MAXARRAY];
char s[MAXLEN];
int len;
int memo[MAXARRAY][MAXARRAY][MAXLEN];
int dr[d] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[d] = {0, 0, -1, 1, -1, -1, 1, 1};

int searchPath(int row, int col, int step)
{
	if(step == len)
		return 1;
	int result = memo[row][col][step];
	if(result > 0)
		return result;
	int i, j, k;
	result = 0;
	for(k=0; k<d; k++)
	{
		i = row + dr[k];
		j = col + dc[k];
		if(i>=0 && i<m && j>=0 && j<n)
			if(map[i][j] == s[step])
			{
				result += searchPath(i, j, step+1);
				if(result > MAX)
					return MAX + 1;
			}
	}
	memo[row][col][step] = result;
	return result;
}

void main()
{
	int times, i, j, total;
	scanf("%d", &times);
	while(times>0)
	{
		times--;
		total = 0;
		memset(memo, 0, sizeof(int)*MAXARRAY*MAXARRAY*MAXLEN);
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++)
				scanf("%s", map[i]);
		scanf("%s", s);
		len = strlen(s);
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
			{
				if(map[i][j] == s[0])
				{
					total += searchPath(i, j, 1);
					if(total > MAX)
					{
						total = -1;
						goto stop;
					}
				}
			}
		stop:
		printf("%d\n", total);
	}
}