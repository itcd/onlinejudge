/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=614
/// http://renkai.org/2011/08/uva673-%E5%88%B7%E6%B0%B4%E9%A2%98%E5%95%A6/

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

bool match(char left, char right)
{
	return left == '(' && right == ')' || left == '[' && right == ']';
}

int main()
{
	const int N = 320;
	char num[N];
	cin.getline(num, N);
	int n = atoi(num);
	while (n-- > 0)
	{
		stack<char> s;
		string str;
		getline(cin, str);
		for (int i=0; i<str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else
			{
				if (str[i] == ')' || str[i] == ']')
				{
					if (!s.empty() && match(s.top(), str[i]))
					{
						s.pop();
					} 
					else
					{
						s.push(str[i]);
						break;
					}	
				}
			}
		}
		if (s.empty())
		{
			cout<<"Yes"<<endl;
		} 
		else
		{
			cout<<"No"<<endl;
		}	
	}

	return 0;
}
