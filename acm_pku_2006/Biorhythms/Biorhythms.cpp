#include<iostream>
using namespace std;

void main()
{
	//初始化数据
	const int P=23, E=28, I=33, max=P*E*I;
	int pAry[E*I+1], eAry[P*I+1], iAry[P*E+1], peAry[I+1];
	int j, num;
	int day[1000];
	for(j=0; j<1000; j++)
		day[j]=max;
	pAry[0]=eAry[0]=iAry[0]=peAry[0]=0;
	for(j=1; j<E*I+1; j++)
	{
		pAry[j]=P+pAry[j-1];
	}
	for(j=1; j<P*I+1; j++)
	{
		eAry[j]=E+eAry[j-1];
	}
	for(j=1; j<P*E+1; j++)
	{
		iAry[j]=I+iAry[j-1];
	}
	for(j=1; j<I+1; j++)
	{
		peAry[j]=P*E+peAry[j-1];
	}

	int p, e, i, d;
	int p0, e0, i0, p1, e1, i1;
	num=0;
	cin>>p>>e>>i>>d;
	while(p>=0 && e>=0 && i>=0 && d>=0)
	{
		p0=0;
		e0=0;
		i0=0;
		while(p0<=E*I && e0<=P*I && i0<=P*E)
		{
			p1=p+pAry[p0];	
			e1=e+eAry[e0];
			i1=i+iAry[i0];
			if(p1>d && p1==e1 && e1==i1)
			{
				day[num]=p1-d;
				break;
			}

			if(p1<e1)
			{
				if(p1<i1)
					p0++;
				else//i1<p1<e1
					i0++;
			}else
			{
				if(e1<i1)
					e0++;
				else//i1<e1<p1
					i0++;
			}
		}
		num++;
		cin>>p>>e>>i>>d;
	}

	for(j=0; j<num; j++)
		cout<<"Case "<<j+1<<": the next triple peak occurs in "<<day[j]<<" days."<<endl;

	//getchar();
	//getchar();
}