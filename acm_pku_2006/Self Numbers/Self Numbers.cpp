#include<iostream>
using namespace std;

int kaprekar(int m)
{
	if(m<10)    return m;
	else
		return kaprekar(m/10)+m%10;	
}

void main()
{
	int i;
	int a;
	int selfnum[10001]={0};
	for(i=1;i<10001;i++)
	{	
		a=i+kaprekar(i);
		if(a<10001)
			selfnum[a]=1;
		if(!selfnum[i])
			cout<<i<<endl;
	}

	//getchar();
}