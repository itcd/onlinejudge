//2007»ª¹¤ACM A
#include <iostream>
#include <stdio.h>
using namespace std;

inline int getLength(int n)
{
	int len = 0;
	while(n > 0)
	{
		len++;
		n = n>>1;
	}
	return len;
}

inline void showBin(int n)
{
	int i, len = getLength(n);
	for(i=len-1; i>=0; i--)
		printf("%d ", (n>>i)&1);
	printf("\n");
}

inline int ploymultiple(int n1, int n2)
{
	int n = 0, degree = 0;
	while(n2 > 0)
	{
		if((n2 & 1) > 0)
			n = n ^ (n1<<degree);
		n2 = n2>>1;
		degree++;
	}
	return n;
}

inline int modulo(int n1, int n2)
{
	int len1 = getLength(n1), len2 = getLength(n2), diff = len1 - len2;
	if(diff < 0)
		return n1;
	int n = n1>>diff;
	while(diff > 0)
	{
		if((n>>(len2-1)) > 0)
			n = n ^ n2;
		diff--;
		n = (n<<1) | ((n1>>diff) & 1);
	}
	if((n>>(len2-1)) > 0)
			n = n ^ n2;
	return n;
}

void _main()
{
	int n1, n2, n3;
	int t, i, n, add;
	scanf("%d\n", &t);
	while(t > 0)
	{
		t--;
		n1 = n2  = n3 = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &add);
			n1 = (n1<<1) + add;
		}
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &add);
			n2 = (n2<<1) + add;
		}
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &add);
			n3 = (n3<<1) + add;
		}
		//printf("%d\t", n1);
		//showBin(n1);
		//printf("%d\t", n2);
		//showBin(n2);
		//printf("%d\t", n3);
		//showBin(n3);
		n = ploymultiple(n1, n2);
		//printf("%d ", getLength(n));
		//showBin(n);		
		n = modulo(n, n3);
		printf("%d ", getLength(n));
		showBin(n);
	}
}