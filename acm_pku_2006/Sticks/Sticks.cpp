#include<iostream>
using namespace std;

const int maxSize=64;

//void divide_Element(int stick[], int n, int m, int mean, int group[], int &count)//按元素个数递归搜索，参数说明：stick数组，sticks数量，分组数量，组平均值，分组数组，分组方案计数器
//{
//	int i;
//
//	if(n==0)
//	{
//		count++;
//		return;
//	}
//
//	for(i=0; i<m; i++)
//	{
//		if(group[i]<mean)
//		{
//			group[i]+=stick[n-1];
//			if(group[i]<=mean)
//			{
//				divide_Element(stick, n-1, m, mean, group, count);
//				if(count>0)
//					return;
//			}
//			group[i]-=stick[n-1];
//		}
//	}
////}

void divide_Group(int stick[], int n, int m, int mean, int group[], bool unused[], int &count)//按分组递归搜索，参数说明：stick数组，sticks数量，分组数量，组平均值，分组数组，标记元素是否已使用的数组，分组方案计数器
{
	int i;

	if(m==0)
	{
		count++;
		return;
	}

	for(i=n-1; i>-1; i--)
	{
		if(unused[i])
		{
			if(stick[i]+group[m-1]<=mean)
			{
				group[m-1]+=stick[i];
				unused[i]=false;

				if(group[m-1]<mean)
					divide_Group(stick, n, m, mean, group, unused, count);
				else
					divide_Group(stick, n, m-1, mean, group, unused, count);

				if(count>0)
					return;

				group[m-1]-=stick[i];
				unused[i]=true;
			}
		}
	}
}

bool isDividable(int stick[], int n, int m, int mean)//divide n numbers into m groups, the sum of each group is mean
{
	int i;
	int group[maxSize];
	bool unused[maxSize];
	int count;

	count=0;
	for(i=0; i<m; i++)
	{
		group[i]=0;
		unused[i]=true;
	}

	divide_Group(stick, n, m, mean, group, unused, count);
	if(count>0)
		return true;
	else
		return false;
}

void main()
{
	int n, i, j, k, temp, sum, mean;
	int len[maxSize];
	int stick[maxSize];
	//int s[maxSize];
	int count=0;

	cin>>n;
	while(n>0)
	{
		sum=0;
		for(i=0; i<n; i++)
		{
			cin>>stick[i];
			sum+=stick[i];
		}
		for(i=0; i<n-1; i++)//sort(upwards)
			for(j=i+1; j<n; j++)
			{
				k=i;
				if(stick[j]<k)
					k=j;
				if(k!=i)
				{
					temp=stick[i];
					stick[i]=stick[j];
					stick[j]=temp;
				}
			}
					
		////取头尾
		//temp=int(n/2);
		//for(j=0; j<temp; j++)
		//{
		//	s[2*j]=stick[j];
		//	s[2*j+1]=stick[n-1-j];
		//}
		//if(n%2>0)
		//	s[2*j]=stick[j];

		//最小长度从数组中的最大元素的值开始试
		len[count]=sum;
		for(mean=stick[n-1]; mean<=sum; mean++)
		{
			if(sum%mean==0 && (stick[n-1]==mean || stick[0]+stick[n-1]<=mean))
			{
				if(isDividable(stick, n, sum/mean, mean))
				{
					len[count]=mean;
					break;				
				}
			}
		}			
		count++;
		cin>>n;
	}

	for(i=0; i<count; i++)
	{
		cout<<len[i]<<endl;
	}

	getchar();
	getchar();
}