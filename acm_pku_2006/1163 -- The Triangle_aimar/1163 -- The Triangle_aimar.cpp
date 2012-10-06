#include<iostream>
using namespace std;


void main()
{
	int i,j;
	int temp1;
	int temp2;
	int num;
	int max;
	cin>>num;
	int t[100][100]={0};
	int weight[100][100]={0};
	for(i=0;i<num;i++)//for(i=0;i<num+1;i++)
	{
		for(j=0;j<=i;j++)//for(j=0;j<i;j++)
			cin>>t[i][j];
	}

	weight[0][0]=t[0][0];
	
	for(i=0;i<num;i++)//for(i=1;i<num+1;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j<=i)
			{
				temp1=0;
				temp2=0;
				if(j>0)
					temp1=weight[i-1][j-1];
				if(j<i)
					temp2=weight[i-1][j];
				weight[i][j]=(temp1>temp2?temp1:temp2)+t[i][j];
			}
		}
	}
	//for(i=0; i<num+1; i++)
	//{
	//	for(j=0;j<i;j++)
	//		cout<<weight[i][j]<<ends;
	//	cout<<endl;
	//}
	//cout<<endl;

	//for(j=0;j<num;j++)
	//{
	//	if(weight[num][j]>weight[num][j+1] && weight[num][j]>max)  
	//		max=weight[num][j];
	//	else if(weight[num][j+1]>max)
	//		max=weight[num][j+1];
	//}

	//这样找最大值更清晰
	max=0;
	for(j=0; j<num; j++)
	{
		if(weight[num-1][j]>max)
			max=weight[num-1][j];
	}
	cout<<max;
	getchar();
	getchar();
	getchar();
}
//#include<iostream>
//using namespace std;
//
//void main()
//{
//	int i,j;
//	int temp1;
//	int temp2;
//	int num;
//	int max;
//	int t[100][100]={0};
//	int weight[100][100]={0};
//
//	cin>>num;
//	for(i=0;i<num;i++)
//	{
//		for(j=0;j<=i;j++)
//			cin>>t[i][j];
//	}
//
//	weight[0][0]=t[0][0];
//	
//	for(i=0;i<num;i++)
//	{
//		for(j=0;j<=i;j++)
//		{
//			if(j<=i)
//			{
//				temp1=0;
//				temp2=0;
//				if(j>0)
//					temp1=weight[i-1][j-1];
//				if(j<i)
//					temp2=weight[i-1][j];
//				weight[i][j]=(temp1>temp2?temp1:temp2)+t[i][j];
//			}
//		}
//	}
//	//for(i=0; i<num+1; i++)
//	//{
//	//	for(j=0;j<i;j++)
//	//		cout<<weight[i][j]<<ends;
//	//	cout<<endl;
//	//}
//	//cout<<endl;
//	//for(j=0;j<num;j++)
//	//{
//	//	if(weight[num][j]>weight[num][j+1] && weight[num][j]>max)  
//	//		max=weight[num][j];
//	//	else if(weight[num][j+1]>max)
//	//		max=weight[num][j+1];
//	//}
//	max=0;
//	for(j=0; j<num; j++)
//	{
//		if(weight[num-1][j]>max)
//			max=weight[num-1][j];
//	}
//	cout<<max;
//
//	//getchar();
//	//getchar();
//}