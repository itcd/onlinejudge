#include <iostream>
using namespace std;

void main()
{
	int n,m;
	int i,j;
	int k;
	int count;
	char dna[100][50];
	int sum[100]={0};
	int sum_temp[50];
	int temp;

	cin>>n>>m;
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
            cin>>dna[i][j];  
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			count=0;
		    for(k=j+1;k<n;k++)
		    {
			    if(dna[i][j]>dna[i][k]) 
				{
					count++;
					//sum[i]++;
				}
				
		    }
			//cout<<count<<ends;
			sum[i]+=count;
		}
		//cout<<endl;
	}

	for(i=0;i<m;i++)
	{
		sum_temp[i]=i;
	}
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
		{
			if(sum[j]<sum[k])
			{
				k=j;
			}
		}
		if(k!=i)
		{
				temp=sum[i];
				sum[i]=sum[k];
				sum[k]=temp;
				temp=sum_temp[i];
				sum_temp[i]=sum_temp[k];
				sum_temp[k]=temp;
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<dna[sum_temp[i]][j];
		cout<<endl;
	}

	//getchar();
	//getchar();
}

/*
#include <iostream>
using namespace std;

void main()
{
	int n,m;
	int i,j;
	int k;
	//int count;
	char dna[1000][1000];
	int sum[1000]={0};
	int sum_temp[1000];
	int temp;

	cin>>n>>m;
    for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
            cin>>dna[i][j];  
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n-1;j++)
		{
			//count=0;
		    for(k=j+1;k<n;k++)
		    {
			    if(dna[i][j]>dna[i][k]) 
				{
					//count++;
					sum[i]++;
				}
				
		    }
			//cout<<count<<ends;
			//sum[i]+=count;
		}
		//cout<<endl;
	}

	for(i=0;i<m;i++)
	{
		sum_temp[i]=i;
	}
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
		{
			if(sum[j]<sum[k])
			{
				k=j;
			}
		}
		if(k!=i)
		{
				temp=sum[i];
				sum[i]=sum[k];
				sum[k]=temp;
				temp=sum_temp[i];
				sum_temp[i]=sum_temp[k];
				sum_temp[k]=temp;
		}
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<dna[sum_temp[i]][j];
		cout<<endl;
	}

	//getchar();
	//getchar();
}
*/