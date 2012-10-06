#include<iostream>
using namespace std;

int main()
{
	const int n=12;
	double a[n];
	double sum=0;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<"$"<<int(100*sum/n+0.5)/100.0<<endl;
	return 0;
}