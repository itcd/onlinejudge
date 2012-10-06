#include <iostream>
#include <stdio.h>
using namespace std;

void main()
{	
	const int MAX = 101;	
	int row[MAX], mx[MAX][MAX];

	int m,n;

	scanf("%d", &n);
	m = n;

	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < m;j++)
		{
			scanf("%d", &mx[i][j]);
		}
	}


	int totalMax = -3000000;

	for(int t = 0;t < m;t++)
	{

		for(int k = 0; k <= t;k++)
		{
			int x = 0;

			if(k != t)
			{
				for(int j = 0;j < m;j++)
				{
					mx[k][j] += mx[t][j];
				}
				x = k;
			}
			else
			{
				x = t;
			}

			/////////////////////////////////////
			int max = -3000000;
			int cMax = -3000000;

			/*for(int j = 0;j < m;j++)
			{
			row[j] = mx[0][j];
			}*/

			int c = mx[x][0];
			cMax = c;

			for(int j = 1;j < m;j++)
			{
				if(mx[x][j] > 0)
				{
					if(cMax < 0)
					{
						c = mx[x][j];
						cMax = c;
					}
					else
					{
						c += mx[x][j];				
					}
				}
				else
				{
					if(cMax < 0)
					{
						if(mx[x][j] > cMax)
						{
							cMax = mx[x][j];
						}
					}
					else
					{
						if(mx[x][j] + c < 0)
						{
							if(c > cMax)
							{
								cMax = c;
							}
							c = 0;
						}
						else
						{
							if(c > cMax)
							{
								cMax = c;
							}
							c = mx[x][j] + c;
						}
					}
				}
			}

			if(c > cMax)
			{
				cMax = c;
			}
			///////////////////////////////////////////

			if(totalMax < cMax)
			{
				totalMax = cMax;
			}

		}
	}

	printf("%d\n", totalMax); 
} 