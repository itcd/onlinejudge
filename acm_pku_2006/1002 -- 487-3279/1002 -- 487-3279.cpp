#include <iostream>
#include <iomanip>
#include <algorithm>
//#include <math.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string>
#include <string.h>
using namespace std;

//const int LEN=7;

//生成测试数据的函数
// int to char
//char intToChar(int i)
//{
//	char c[8][3]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y'};
//	if (i>1 && i<10)
//		return c[i-2][rand()%3];
//	else
//		return '-';
//}

//void genOneRandomLine(int num[], int n)
//{
//	char str[2*LEN+2];
//	int i;
//	for (i=0; i<n; i++)
//	{
//		str[i]=intToChar(num[i]);
//		cout<<str[i];
//	}
//	cout<<endl;
//}

//int GenRandomLines(int line)
//{
//	int num[2*LEN+2];
//	int i, j, count;
//	int sum=0;
//	while (line>0)
//	{
//		count=i=0;
//		while (count<LEN)
//		{
//			do 
//			{
//				num[i]=rand()%10;
//			} while(num[i]==1);
//			if (num[i]>1 && num[i]<10)
//				count++;
//			i++;
//		}
//		j=rand()%LEN;
//		sum+=j+1;
//		while (j>=0)
//		{
//			genOneRandomLine(num, i);
//			j--;
//		}
//		for (j=0; j<i; j++)
//		{
//			cout<<num[j];
//		}
//		cout<<endl<<endl;
//		line--;
//	}
//	return sum;
//}

//解题的函数
//char to int
int charToInt(char c)
{
	/*
	A, B, and C map to 2 
	D, E, and F map to 3 
	G, H, and I map to 4 
	J, K, and L map to 5 
	M, N, and O map to 6 
	P, R, and S map to 7 
	T, U, and V map to 8 
	W, X, and Y map to 9
	*/
	switch(c)
	{
	case 'A':
	case 'B':
	case 'C':
		return 2;
	case 'D':
	case 'E':
	case 'F':
		return 3;
	case 'G':
	case 'H':
	case 'I':
		return 4;
	case 'J':
	case 'K':
	case 'L':
		return 5;
	case 'M':
	case 'N':
	case 'O':
		return 6;
	case 'P':
	case 'R':
	case 'S':
		return 7;
	case 'T':
	case 'U':
	case 'V':
		return 8;
	case 'W':
	case 'X':
	case 'Y':
		return 9;
	default:
		if (c>='0' && c<='9')
			return c-'0';
		else
			return -1;
	}
}

//void charToInt_Show(char *s)
//{
//	int i=0, j;
//	while (s[i]!='\0')
//	{
//		j=charToInt(s[i]);
//		if (j>=0)
//			cout<<j;
//		else
//			cout<<"-";
//		i++;
//	}
//	cout<<endl;
//}

//void charAryToIntAry(char str[], int strLen, int num[], int &numLen)
//{
//	int i, j;
//	int bit;
//	j=0;
//	for (i=0; i<strLen; i++)
//	{
//		bit=charToInt(str[i]);
//		if (bit>1 && bit<10)
//		{
//			num[j]=bit;
//			j++;
//		}
//
//	}
//	numLen=j;
//}

int charAryToInt(const char str[], int strLen)
{
	int i, bit;
	int num=0;
	for (i=0; i<strLen; i++)
	{
		bit=charToInt(str[i]);
		if (bit>=0 && bit<10)
		{
			num*=10;
			num+=bit;
		}
	}
	return num;
}

void main()
{
	//const int MAX=100000;
	int lines, count;
	bool no_duplicates=true;
	char s[64];
	//string str;
	int num[100000];
	int i;

	//srand( (unsigned)time( NULL ) );
	cin>>lines;
	//cout<<GenRandomLines(lines);
	getchar();

	for (i=0; i<lines; i++)
	{
		//cin>>str;
		//num[i]=charAryToInt(str.data(), (int)str.length());
		gets(s);
		num[i]=charAryToInt(s, (int)strlen(s));
	}
	sort(num, num+lines);

	for (i=0; i<lines; i++)
	{
		if (i>0 && num[i]==num[i-1])
			count++;
		else
			count=1;
		if ((i<lines-1 && num[i]!=num[i+1]) || i==lines-1)
		{
			if (count>1)
			{
				cout<<setfill('0')<<setw(3)<<num[i]/10000<<"-"<<setw(4)<<num[i]%10000<<" "<<count<<endl;
				no_duplicates=false;
			}
		}
	}
	if (no_duplicates)
		cout<<"No duplicates."<<endl;

	//getchar();
	//getchar();
}
//int len, k;
//double num;
//cin>>num;
//len=int(log10(num)+1);
//k=(int)pow(10., len-3);
//cout<<int(num)/k<<"-"<<int(num)%k;

/*
int time=0;
bool change=false;
for (i=0;i<n-1;i++)
{
	if (val[i]==val[i+1])
	{
		change=true;
		time++;
		if (i!=n-2)
		{
			continue;
		}
		else
		{
			//cout<<val[i]/10000<<"-"<<val[i]%10000<<" "<<time+1<<endl;
			cout<<setfill('0')<<setw(3)<<val[i]/10000<<"-"<<setfill('0')<<setw(4)<<val[i]%10000<<" "<<time+1<<endl;
			time=0;
		}
	}
	if (time>0)
	{
		cout<<setfill('0')<<setw(3)<<val[i]/10000<<"-"<<setfill('0')<<setw(4)<<val[i]%10000<<" "<<time+1<<endl;
		time=0;
	}
}
if (!change)
{
	cout<<"No duplicates."<<endl;
} 
*/
/*
1228364 lsz 1002 Accepted 504K 405MS C++ 3.41K 2006-05-17 11:58:08.0 
1228059 lsz 1002 Accepted 504K 436MS C++ 3.37K 2006-05-17 01:27:45.0 
1228044 lsz 1002 Accepted 504K 1327MS C++ 3.28K 2006-05-17 01:06:22.0 
1227223 aimar_dream 1002 Accepted 512K 1655MS C++ 1.6K 2006-05-16 12:54:20.0 
*/