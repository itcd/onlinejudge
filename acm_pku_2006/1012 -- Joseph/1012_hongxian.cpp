#include <iostream>
using namespace std;

int _main()
{
	int i,point;
	int k,m;
	long res[14];
	for (k=1;k<=13;k++)
	{
		m=k+1;
		while (1)
		{
			point=0;
			for (i=k;i>=1;i--)
			{
				point=(point+m)%(k+i);
				if ((point!=0)&&(point<=k)) break;
				point--;
				if (point<0) point=0;
			}
			if (i==0) break;
			m++;
			point=0;
			for (i=k;i>=1;i--)
			{
				point=(point+m)%(k+i);
				if ((point!=0)&&(point<=k)) break;
				point--;
				if (point<0) point=0;
			}
			if (i==0) break;
			m=m+k;
		}
		res[k]=m;
	}
	//for(i=0; i<14; i++)
	//	cout<<res[i]<<"\t";
	cin>>k;	
	while (k>0)
	{
		
		cout<<res[k]<<endl;
		cin>>k;
	}
	return 0;
}
