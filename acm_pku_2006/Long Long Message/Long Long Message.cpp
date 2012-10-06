#include<iostream>
#include <string> 
#include <stdio.h> 
using namespace std;

void main()
{
	string s1, s2, big, small;
	int i, j, l1, l2, len1, len, maxi, l, r, mid;
	int maxLen=0;
	basic_string <char>::size_type index;

	cin>>s1>>s2;

	l1=int(s1.length());
	l2=int(s2.length());

	if(l1<l2)
	{
		small=s1;
		len1=l1;
		big=s2;
	}else
	{
		small=s2;
		len1=l2;
		big=s1;
	}

	//cout<<len1<<endl<<small<<endl<<big<<endl;

	for(i=0; i<len1; i++)
	{
		len=len1-i+1;
		for(j=maxLen+1; j<len; j*=2)
		{
			index=big.find(small.substr(i, j),0);
			if (index != string::npos )
			{
				maxLen=j;
				maxi=i;
				//cout<<small.substr(i, j)<<"\t"<<j<<endl;
			}
		}

		//对长度二分查找
		mid=0;
		l=0;
		r=maxLen;
		while(l+1<r || mid!=(l+r)/2)
		{
			mid=(l+r)/2;
			j=mid+maxLen;
			if(j<len)
			{
				index=big.find(small.substr(i, j),0);
				if (index != string::npos )
				{			
					l=mid;
					//cout<<small.substr(i, j)<<"\t"<<j<<endl;
				}else
					r=mid;
			}else
			{
				r=mid;
			}
		}
		if(mid>0)
		{
			maxLen=mid+maxLen;
			//cout<<small.substr(i, j)<<"\t"<<j<<endl;
		}

	}

	//cout<<maxLen<<endl;
	//每次长度加2
	//if(j<len1-maxi+1)
	//{
	//	index=big.find(small.substr(maxi, j),0);
	//	if (index != string::npos )
	//	{
	//		maxLen=j;				
	//		cout<<small.substr(maxi, j)<<endl;
	//	}
	//}

	printf("%d", maxLen);
	//cout<<maxLen<<endl;

	//getchar();
	//getchar();
}