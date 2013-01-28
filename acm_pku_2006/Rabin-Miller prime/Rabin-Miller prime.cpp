#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void main()
{
	int n;
	cout<<"Input a integer:\n";
	cin>>n;
	if (n>1)
	{
		cout<<(int)pow(2., n-1)%n<<endl;
	}else
		cout<<n<<"<2"<<endl;
	getchar();
	getchar();
}