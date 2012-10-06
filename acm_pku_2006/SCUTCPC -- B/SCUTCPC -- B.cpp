#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

int convert(char c)
{
	switch(c)
	{
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
		default:return 0;
	}
}

int rometoDec(const char *s, int len)
{
	int i=0, sum=0;
	while(i<len)
	{
		if(i<len-1 && convert(s[i+1])>convert(s[i]))
		{
			sum+=convert(s[i+1])-convert(s[i]);
			i+=2;
		}else
		{
			sum+=convert(s[i]);
			i++;
		}
	}
	return sum;
}

void dectoRome(int n, char *s)
{
	/*
	998
	M	D	CD	L	XL	V	III
	0	1	4	1	4	1	3
	1	0	0	0	-1	1	3
	XMVIII
	*/
	int digit[7]={0};
	int num[7]={1000, 500, 100, 50, 10, 5, 1};
	char sign[7]={'M', 'D', 'C', 'L', 'X', 'V', 'I'};
				//1000	500	100	  50	10	 5	 1
	int i, j, k, sum=n;
	for(i=0; i<7; i++)
	{
		digit[i]=sum/num[i];
		sum=sum%num[i];
	}
	for(i=6; i>=0; i--)//处理进位
	{
		if(i>0 && i%2==0 && digit[i]>=4)
		{	
			digit[i-1]++;
			digit[i]-=5;
		}
		if(i>0 && i%2!=0 && digit[i]>=2)
		{
			digit[i-1]++;
			digit[i]-=2;		
		}
	}
	//生成罗马数字字符串
	int len=0;
	for(i=0; i<7; i++)
	{
		len+=abs(digit[i]);
	}
	s[len]='\0';
	j=len-1;
	i=6;
	int negative;
	while(i>=0 && j>=0)
	{
		if(digit[i]>0)
		{
			for(k=0; k<digit[i]; k++)
			{
				s[j]=sign[i];
				j--;
			}
		}
		if(digit[i]<0)
		{
			negative=i;
			do{
				i--;
			}while(digit[i]==0);
			s[j]=sign[i];
			j--;
			s[j]=sign[negative];
			j--;
		}
		i--;	
	}
}

int GCD(int x, int y)
{
	int i, mod;
	if(x>y)
	{
		i=x;
		x=y;
		y=i;
	}
	while(x>0)
	{
		mod=y%x;
		y=x;
		x=mod;
	}
	return y;
}

void main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n1, n2, mod;
	char s[1000];
	string s1, s2;
	while(fin>>s1>>s2)
	{
		cout<<s1<<ends<<s2<<endl;
		n1=rometoDec(s1.data(), (int)s1.length());
		n2=rometoDec(s2.data(), (int)s2.length());
		mod=GCD(n1, n2);
		dectoRome(mod, s);
		cout<<n1<<ends<<n2<<ends<<mod<<"\t";
		cout<<s<<endl;
		fout<<s<<endl;
	}
	getchar();
}