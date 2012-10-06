#include<iostream>
using namespace std;

void main()
{
	int i,j, temp1, temp2, num, max;
	int t[100][100], weight[100][100];

	cin>>num;

	for(i=0; i<num; i++)
		for(j=0; j<=i; j++)
			cin>>t[i][j];

	weight[0][0]=t[0][0];
	for(i=1;i<num;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j<=i)
			{
				temp1=0;	temp2=0;
				if(j>0)
					temp1=weight[i-1][j-1];
				if(j<i)
					temp2=weight[i-1][j];
				weight[i][j]=(temp1>temp2?temp1:temp2)+t[i][j];
			}
		}
	}

	max=0;
	for(i=0; i<num; i++)
	{
		for(j=0; j<=i; j++)
		{
			if(weight[i][j]>max)
				max=weight[i][j];
			//cout<<weight[i][j]<<"\t";
		}
		//cout<<endl;
	}
	cout<<max<<endl;

	//getchar();
	//getchar();
}