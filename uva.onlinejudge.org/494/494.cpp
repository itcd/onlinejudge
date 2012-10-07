/// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=435
/// http://www.reait.com/1/post/2012/3/uva-494.html

#include <iostream>
#include <cstdio>
using namespace std;

bool is_letter(char c)
{
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

bool count_words(char c, char &c_previous, int &sum)
{
	if (c == '\n')
	{
		if (sum == 0)
		{
			return false;
		} 
		else
		{
			cout<<sum<<endl;
			sum = 0;
		}
	} 
	else
	{
		if (is_letter(c) && !is_letter(c_previous))
		{
			sum++;
		}
	}
	c_previous = c;
	return true;
}

int main()
{
	char c, c_previous = '\0';
	int sum = 0;
	while ((c = getchar()) != EOF)
	{
		if (!count_words(c, c_previous, sum))
		{
			break;
		}
	}

	return 0;
}
