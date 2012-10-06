#include<iostream>using namespace std;
void main()
{
	float a[12];
	float total = 0;
	for(int i = 0;i < 12;i++)
	{
		cin>>a[i];
		total = total + a[i];
	}
	total = total / 12;
	total = static_cast <int>(total * 100) / 100.0;	cout<<"$"<<total<<endl;	getchar();}