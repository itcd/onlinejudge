#include <iostream>
#include <stdio.h>
using namespace std;

void main()
{
	const int MAX = 128;
	int n, m, i, j, result = -32768;
	int row[MAX], rowdump[MAX][MAX], all[MAX][MAX];
	scanf("%d", &n);
	m = n;
	memset(all, 0, sizeof(int)*MAX*MAX);
	while(m>0)
	{
		m--;
		for(i=0; i<n; i++)
		{
			scanf("%d", &row[i]);
			rowdump[i][i] = row[i];
			for(j=0; j<i; j++)
			{
				rowdump[i][j] = rowdump[i-1][j] + row[i];
				//printf("%d\t", rowdump[i][j]);
			}
			//printf("%d\n", rowdump[i][i]);
		}
		for(i=0; i<n; i++)
			for(j=0; j<i; j++)
			{
				if(all[i][j] > 0)
					all[i][j] += rowdump[i][j];
				else
					all[i][j] = rowdump[i][j];
				if(all[i][j] > result)
					result = all[i][j];
			}
	}
	printf("%d\n", result);
}