/// http://blog.sina.com.cn/s/blog_7785f1270100y0gl.html

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n-- > 0)
	{
		int m;
		cin>>m;
		int sum = 0;
		while (m-- > 0)
		{
			int a, b, c;
			cin>>a>>b>>c;
			sum += a * c;
		}
		cout<<sum<<endl;
	}

	return 0;
}
