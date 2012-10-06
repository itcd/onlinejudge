#include <iostream>
#include <stdio.h>
using namespace std;

const int KMAX = 14;

inline int Joseph(int k)
{
	int max[KMAX];
	int pos, d, i, j;
	for(i=0,j=(k<<1); i<k; i++,j--)
	{
		max[i] = j;
	}
	d = k;
	i = 0;
	while(i < k)
	{
		pos = 0;
		for(i=0; i<k; i++)
		{
			pos = (pos + d)%max[i];
			if(pos<k)
				break;
		}
		d++;
	}
	return d;
}

void main()
{
	
	int i, k;
	int joseph[KMAX];
	for(i=0; i<KMAX; i++)
		joseph[i] = Joseph(i);
	scanf("%d", &k);
	while(k>0)
	{
		printf("%d\n", joseph[k]);
		scanf("%d", &k);
	}
}
