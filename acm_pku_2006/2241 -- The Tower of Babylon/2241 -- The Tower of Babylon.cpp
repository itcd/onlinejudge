#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 90;

struct Block
{
	int x, y, z;
};

Block blocks[MAX];

bool probableGreater(Block b1, Block b2)
{
	return b1.x * b1.y > b2.x * b2.y;
}

inline bool strictGreater(Block b1, Block b2)
{
	return b1.x > b2.x && b1.y > b2.y;
}

inline int maxHeight(int n)
{
	int i, j, h[MAX], temp;
	int result = h[0] = blocks[0].z;
	for(i=1; i<n; i++)
	{
		for(j=0; j<i; j++)
		{
			if(strictGreater(blocks[j], blocks[i]))
			{
				temp = h[j] + blocks[i].z;
				if(temp > h[i])
					h[i] = temp;
			}
		}
		if(blocks[i].z > h[i])
			h[i] = blocks[i].z;
		if(h[i] > result)
			result = h[i];	
	}
	return result;
}

void main()
{
	int n, x, y, z, i, j, caseNo = 1;
	scanf("%d", &n);
	while(n>0)
	{
		j = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			if(x<y)
			{
				blocks[j].x = x;
				blocks[j].y = y;
			}else
			{
				blocks[j].x = y;
				blocks[j].y = x;			
			}
			blocks[j].z = z;
			j++;
			if(z != y)
			{
				if(x<z)
				{
					blocks[j].x = x;
					blocks[j].y = z;				
				}else
				{
					blocks[j].x = z;
					blocks[j].y = x;
				}
				blocks[j].z = y;
				j++;
			}
			if(z != x)
			{
				if(y<z)
				{
					blocks[j].x = y;
					blocks[j].y = z;
				}else
				{
					blocks[j].x = z;
					blocks[j].y = y;				
				}
				blocks[j].z = x;
				j++;
			}
		}
		sort(blocks, blocks + j, probableGreater);
		for(i=0; i<j; i++)
			printf("%d\t%d\t%d\n", blocks[i].x, blocks[i].y, blocks[i].z);
		printf("Case %d: maximum height = %d\n", caseNo, maxHeight(j));
		scanf("%d", &n);
		caseNo++;
	}
}
