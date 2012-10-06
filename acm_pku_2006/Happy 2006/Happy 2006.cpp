#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

////bool rp(int g, int l)//{//	if(l==1)    return 0;//	int nl = g % l;//	if(nl == 0){return 1;}//	else if(nl == 1){return 0;}//	else//	{//		return rp(l,nl);//	}//} 

int GCD(int m,int n)
{
		if(n==0)
				return m;
			else
				return GCD(n,m%n);
}


void main()
{
	int m,n;
 //   cin>>m>>n;
	//cout<<rp(m,n);
	int i=0;
	int j;
	int k;
	int ary[1000][2];
	int ary_long;

	/*char *s=new char;
	while(s[l]!='\n')
	{	
		l++;
		s[l]=getchar();
		while(s[l]!=' ')
		{
			m1*=10;
			n1='s[l]'-'0';
			m1=n1;
			l++;
			s[l]=getchar();
		}
		m=m1;ary[i][0]=m;
		l+=1;
		s[l]=getchar();
		while(s[l]!='\n')
		{
			m2*=10;
			n2='s[l]'-'0';
			m2=n2;
			l++;
			s[l]=getchar();
		}
		n=m2;ary[i][1]=n;
	
		l=0;i++;
		s[l]=getchar();
	}
	ary_long=i;*/


	//char *s=new char;

	//while(gets(s)!='\n')
	//{
	//	while(strlen(s))
	//	{
	//		while(l<strlen(s))
	//		{
	//			if(s[l]!=32)
	//			{
	//				m1*=10;
	//				n1='s[l]'-'0';
	//				m1=n1*10;
	//			}
	//			else
	//				m=m1;

	//			if(s[l]!='\0')
	//			{

	//				m2*=10;
	//				n2='s[l]'-'0';
	//				m2=n2*10;
	//			}
	//			else
	//				n=m2;
	//		l++;
	//		}
	//	}
	//	ary[i][0]=m;
	//	ary[i][1]=n;
	//	ary_long++;
	//	i++;
	//}
		
    
	while(cin>>m>>n)
	{
		ary[i][0]=m;
		ary[i][1]=n;
		i++;		
	}
    ary_long=i;

	for(i=0;i<ary_long;i++)
	 {
		 k=0;
		for(j=1;j<100000000;j++)
		{
				if(GCD(ary[i][0],j)==1)
				{
					k++;
					if(k==ary[i][1])
					{
						printf("%d\n",j);
						break;
					}
				}
			
		}

	}

	getchar();
	getchar();
}