#include<iostream>
using namespace std;

void main()
{
	int n;
	cin>>n;
	double *x=new double[n];
	double *y=new double[n];
	double *r=new double[n];//stand for r*r
	double max=0;
	int *year=new int[n];
	int i;
	for(i=0; i<n; i++)
	{
		cin>>x[i]>>y[i];
		r[i]=x[i]*x[i]+y[i]*y[i];
		if(r[i]>max)
			max=r[i];
	}
	for(i=0; i<n; i++)
	{
		year[i]=0;
	}
	const double r0=100/3.14159;
	double r2=0;//stand for r*r
	int count=0;
	do
	{
		r2+=r0;
		count++;
		for(i=0; i<n; i++)
		{
			if(year[i]==0 && r2>=r[i])
			{
				year[i]=count;
			}
		}
	}while(r2<max);
	for(i=0; i<n; i++)
	{
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<year[i]<<".\n";
	}
	cout<<"END OF OUTPUT.\n";
}