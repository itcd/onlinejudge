#include <iostream>
#include <string.h>

long i,j,k,n,m,Max;
long a[2][101][101];
long b[101];
long c[101][101];

using namespace std;

int _main()
{
	int T;
	cin>>T;
	for (int t=0;t<T;t++)
	{
		cin>>n;
		memset((void*)a,0,sizeof(a));
		Max=-2147483647;
		for (i=1;i<=n;i++)
		{
			memset((void*)c,0,sizeof(c));
			for (j=1;j<=n;j++)
			{
				cin>>b[j];
				for (k=1;k<=j;k++)
				{
					c[j][k]=c[j-1][k]+b[j];
					//cout<<c[j][k]<<"\t";
				}
				//cout<<endl;
			}
			for (j=1;j<=n;j++)
			{
				for (k=1;k<=j;k++)
				{
					a[1][j][k]=c[j-1][k]+b[j];
					if (a[0][j][k]>0) a[1][j][k]+=a[0][j][k];
					if (a[1][j][k]>Max) Max=a[1][j][k];
					//cout<<a[1][j][k]<<"\t";
				}
				//cout<<endl;
			}
			for (j=1;j<=n;j++)
				for (k=1;k<=j;k++)
					a[0][j][k]=a[1][j][k];
		}
		cout<<Max<<endl;
	}
	return 0;
}
