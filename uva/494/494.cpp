/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=435
/// http://www.reait.com/1/post/2012/3/uva-494.html

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	const int N = 320;
	char str[N];
	while (cin.getline(str, N) && strlen(str) > 0)
	{
		stringstream ss;
		ss<<str;
		string temp;
		int word_count = 0;
		while (ss>>temp)
		{
			word_count++;
		}
		cout<<word_count<<endl;
	}
	return 0;
}
