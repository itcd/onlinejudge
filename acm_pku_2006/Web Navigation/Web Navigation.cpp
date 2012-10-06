#include<iostream>
#include<string>
#include"stack.h"
using namespace std;

void main()
{
	const int max=100;
	AStack<string> back(max);
	AStack<string> forward(max);
	string s1, s2, visit="VISIT";
	cin>>s1;
	//if(s1.compare(visit))
		cin>>s2;
	cout<<s1<<endl<<s2<<endl;

	getchar();
	getchar();
	getchar();
}