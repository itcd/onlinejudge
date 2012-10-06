#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string>
#include <string.h>
using namespace std;

void main()
{
	int i, n, begin, len;
	int s[16];

	cin>>n;
	if (n!=0)
		len=(int)log10((double)abs(n));
	else
		len=0;
	for (i=len; i>=0; i--)//将n每一位分别放入s[]
	{
		s[i]=n%10;
		n/=10;
	}

	begin=++len%3;
	for (i=0; i<len; i++)//输出s[]
	{
		if (i!=0 && (i-begin)%3==0)
			cout<<",";
		cout<<s[i];
	}
	getchar();
	getchar();
}