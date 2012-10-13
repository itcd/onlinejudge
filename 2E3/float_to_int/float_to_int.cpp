#include <iostream>
#include <cmath>
using namespace std;

void main()
{
	for (int i=0; i<10; i++)
	{
		cout<<(int)(sqrt(2)*sqrt(2)*sqrt(2)*sqrt(2))<<"\t";
	}
	cout<<endl;
	for (int i=0; i<10; i++)
	{
		cout<<(int)(sqrt(2.f)*sqrt(2.f)*sqrt(2.f)*sqrt(2.f))<<"\t";
	}
	cout<<endl;
	cout<<(int)sqrt(16.f)<<endl;
	cout<<(int)(sqrt(2.f)*sqrt(2.f)*sqrt(2.f)*sqrt(2.f))<<endl;
}
