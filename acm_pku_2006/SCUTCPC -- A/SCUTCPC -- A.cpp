#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int dec(int i)
{
	switch(i)
	{
		case 0:return 128;
		case 1:return 64;
		case 2:return 32;
		case 3:return 16;
		case 4:return 8;
		case 5:return 4;
		case 6:return 2;
		case 7:return 1;
		default:return 0;
	}
}

int convert(char ary[])
{
	int i, sum=0;
	for(i=0; i<8; i++)
	{
		sum+=(ary[i]-'0')*dec(i);
	}
	return sum;
}

void main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n, i, j, k;
	string s;
	char ary[4][8];
	fin>>n;
	for(k=0; k<n; k++)
	{
		fin>>s;
		cout<<s<<endl;
		for(i=0; i<4; i++)
			for(j=0; j<8; j++)
				ary[i][j]=s[i*8+j];

		cout<<convert(ary[0])<<"."<<convert(ary[1])<<"."<<convert(ary[2])<<"."<<convert(ary[3])<<endl;
		fout<<convert(ary[0])<<"."<<convert(ary[1])<<"."<<convert(ary[2])<<"."<<convert(ary[3])<<endl;
	}
	fin.close();
	fout.close();

	getchar();
}