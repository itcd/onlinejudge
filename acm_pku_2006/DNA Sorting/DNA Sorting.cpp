#include<iostream>
#include<string>
using namespace std;

int calc(const string str, int n)
{
	int i, j, result=0;
	//int count;
	for(i=0; i<n-1; i++)
	{
		//count=0;
		for(j=i+1; j<n; j++)
		{
			if(str[j]<str[i])
				//count++;
				result++;
		}
		//cout<<count<<ends;
		//result+=count;
	}
	return result;
}

void main()
{
	int m, n, i, j, k;
	int tmp;
	string tmpStr;
	cin>>n>>m;
	int *count=new int[m];
	string *s=new string[m];
	for(i=0; i<m; i++)//mÐÐ
	{
		cin>>s[i];
	}
	for(i=0; i<m; i++)
	{
		count[i]=calc(s[i], n);
		//cout<<endl;
	}
	for(i=0; i<m-1; i++)
	{
		k=i;
		for(j=i+1; j<m; j++)
		{
			if(count[j]<count[k])
				k=j;
		}
		if(k!=i)
		{
			tmp=count[i];
			count[i]=count[k];
			count[k]=tmp;
			tmpStr=s[i];
			s[i]=s[k];
			s[k]=tmpStr;
		}
	}
	for(i=0; i<m; i++)
	{
			cout<<s[i]<<endl;
	}

	//getchar();
	//getchar();
}