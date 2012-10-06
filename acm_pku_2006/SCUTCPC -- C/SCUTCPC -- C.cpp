#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int count[4]={1, 0, 1, 1};
string sign[4]={" shata", " hajar", " lakh", " kuti"};
string ary[20];

void main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int num=1, i, j, k, len;
	string s;
	while(fin>>s)
	{
		cout<<s<<endl;
		j=k=len=0;
		i=(int)s.length()-1;
		while(i>=0)
		{
			if(i<(int)s.length()-1)
			{
				if(i-count[j]>=0)
					ary[len]=s.substr(i-count[j], count[j]+1)+sign[k];
				else
				{
					ary[len]=s.substr(i, count[j]+1)+sign[k];
					cout<<"ary[len]=s.substr(i, count[j]+1)+sign[k];\n";
				}
				k=(k+1)%4;
			}else
			{
				if(i-count[j]>=0)
					ary[len]=s.substr(i-count[j], count[j]+1);	
				else
				{
					ary[len]=s.substr(i, count[j]+1);	
					cout<<"ary[len]=s.substr(i, count[j]+1)\n";
				}
			}
			i=i-count[j]-1;
			j=(j+1)%4;
			len++;
		}
		cout<<"   "<<num<<".";
		fout<<"   "<<num<<".";
		for(i=len-1; i>=0; i--)
		{
			cout<<" "<<ary[i];
			fout<<" "<<ary[i];
		}
		cout<<endl;
		fout<<endl;
		num++;
	}
	getchar();
}