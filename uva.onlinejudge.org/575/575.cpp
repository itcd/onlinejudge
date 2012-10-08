/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=516
/// http://www.cnblogs.com/naix-x/archive/2012/07/04/2575745.html

#include <iostream>
#include <string>
using namespace std;

const int N = 64;
unsigned long long power[N];

void calc_power()
{
	power[0] = 1;
	for (int i=1; i<N; i++)
	{
		power[i] = power[i-1] << 1;
	}
}

int main()
{
	calc_power();
	string s;
	cin>>s;
	while (s.length() > 0)
	{
		unsigned long long sum = 0;
		int len = s.length();
		for (int i=0; i<len; i++)
		{
			sum += (s[i] - '0') * (power[len-i] - 1);
		}
		if (sum == 0)
		{
			break;
		}
		cout<<sum<<endl;
		cin>>s;
	}
	return 0;
}
