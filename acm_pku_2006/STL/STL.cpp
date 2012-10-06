#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include <functional> 
#include <stdlib.h> 
#include <time.h> 
#include <iomanip> 
using namespace std;

bool UDgreater(int a, int b)
{
	return a>b;
}

struct point
{
	int x;
	int y;
};

bool smaller(point a, point b)
{
	return a.y<b.y;
}

void main()
{
	//vector<char> v1(10);
	//vector<char>::iterator location;
	//stack<char> s1;
	//char ch;
	//int i;
	//char c[10];
	//for(i=0; i<10; i++)
	//{
	//	c[i]='a'+i;
	//	s1.push(c[i]);
	//}

	//v1.assign(c,c+10);

	//sort( v1.begin( ), v1.end( ) );

	//for(i=0; i<10; i++)
	//{
	//	ch=s1.top();
	//	s1.pop();
	//	cout<<v1[i]<<"\t"<<ch<<endl;
	//}
	//cout<<endl;

	//location=find(v1.begin(), v1.end(), 'd');
	//cout<<location-v1.begin()<<endl;

	int i, j;
	point p[10];
	srand((unsigned)time(NULL));
	for(i=0; i<10; i++)
	{
		p[i].x=rand()%10;
		p[i].y=rand()%10;
	}
	for(i=0; i<10; i++)
	{
		cout<<p[i].x<<"\t"<<p[i].y<<endl;
	}
	cout<<endl;
	sort(p, p+10, smaller);
	for(i=0; i<10; i++)
	{
		cout<<p[i].x<<"\t"<<p[i].y<<endl;
	}
	double n=1;
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<n<<endl;
	printf("%.3f\n",n);
	n=1.2;
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<n<<endl;
	printf("%8.3f\n",n);
	n=1.2345;
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<n<<endl;
	printf("%10.3f\n",n);
	getchar();	
}