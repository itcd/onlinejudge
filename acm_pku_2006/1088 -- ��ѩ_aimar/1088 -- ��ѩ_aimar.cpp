#include<iostream>
using namespace std;


void main()
{
	int i=0,j=0;
	int r=0,c=0;
	int max=0;
	/*int temp1=0,temp2=0,temp3=0,temp4=0;*/
	cin>>r>>c;
	int num[100][100]={0};
	int weight[100][100]={1};
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cin>>num[i][j];
	}


	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			/*temp1=temp2=temp3=temp4=0;*/

			if(i>0 && j>0 && i<r-1 && j<c-1)//is not the boundary of the array
			{
				if(num[i][j]<num[i][j+1])//ÓÒ±ß
				{
					//temp1=weight[i][j]+1;/*+num[i][j+1]*//*;*/
					//weight[i][j+1]=temp1>weight[i][j+1]?temp1:weight[i][j+1];
					if(weight[i][j+1]<weight[i][j]+1)
					weight[i][j+1]=weight[i][j]+1;
				}
				if(num[i][j]<num[i][j-1])//×ó±ß
				{
					//temp2=weight[i][j]+1;/*+num[i][j-1];*/
					//weight[i][j-1]=temp2>weight[i][j-1]?temp2:weight[i][j-1];
					if(weight[i][j-1]<weight[i][j]+1)
					weight[i][j-1]=weight[i][j]+1;
				}
				if(num[i][j]<num[i-1][j])//ÉÏ±ß
				{
					//temp3=weight[i][j]+1;/*+num[i-1][j];*/
					//weight[i-1][j]=temp3>weight[i-1][j]?temp3:weight[i-1][j];
					if(weight[i-1][j]<weight[i][j]+1)
					weight[i-1][j]=weight[i][j]+1;
				}
				if(num[i][j]<num[i+1][j])//ÏÂ±ß
				{
					//temp4=weight[i][j]+1;/*+num[i+1][j];*/
					//weight[i+1][j]=temp4>weight[i+1][j]?temp4:weight[i+1][j];
					if(weight[i+1][j]<weight[i][j]+1)
					weight[i+1][j]=weight[i][j]+1;
				}
				break;
			}

			if(i==0 && j==0)//×óÉÏ½Ç
			{
				if(num[i][j]<num[i][j+1])//ÓÒ±ß
				{
					//temp1=weight[i][j]+1;/*+num[i][j+1];*/
					//weight[i][j+1]=temp1>weight[i][j+1]?temp1:weight[i][j+1];
					if(weight[i][j+1]<weight[i][j]+1)
					weight[i][j+1]=weight[i][j]+1;				
				}
				else if(num[i][j]<num[i+1][j])//ÏÂ±ß
				{
					//temp4=weight[i][j]+1;/*+num[i+1][j];*/
					//weight[i+1][j]=temp4>weight[i+1][j]?temp4:weight[i+1][j];
					if(weight[i+1][j]<weight[i][j]+1)
					weight[i+1][j]=weight[i][j]+1;	
				}
				break;
			}

			if(i==0 && j==c-1)//ÓÒÉÏ½Ç
			{
				if(num[i][j]<num[i][j-1])//×ó±ß
				{
					//temp2=weight[i][j]+1;/*+num[i][j-1];*/
					//weight[i][j-1]=temp2>weight[i][j-1]?temp2:weight[i][j-1];
					if(weight[i][j-1]<weight[i][j]+1)
					weight[i][j-1]=weight[i][j]+1;
				}
				else if(num[i][j]<num[i+1][j])//ÏÂ±ß
				{
					//temp4=weight[i][j]+1;/*+num[i+1][j];*/
					//weight[i+1][j]=temp4>weight[i+1][j]?temp4:weight[i+1][j];
					if(weight[i+1][j]<weight[i][j]+1)
					weight[i+1][j]=weight[i][j]+1;
				}
				break;
			}

			if(i==r-1 && j==0)//×óÏÂ½Ç
			{
				if(num[i][j]<num[i][j+1])//ÓÒ±ß
				{
					//temp1=weight[i][j]+1;/*+num[i][j+1];*/
					//weight[i][j+1]=temp1>weight[i][j+1]?temp1:weight[i][j+1];
					if(weight[i][j+1]<weight[i][j]+1)
					weight[i][j+1]=weight[i][j]+1;		
				}
				else if(num[i][j]<num[i-1][j])//ÉÏ±ß
				{
					//temp3=weight[i][j]+1;/*+num[i-1][j];*/
					//weight[i-1][j]=temp3>weight[i-1][j]?temp3:weight[i-1][j];
					if(weight[i-1][j]<weight[i][j]+1)
					weight[i-1][j]=weight[i][j]+1;	
				}
				break;
			}

			if(i==r-1 && j==c-1)//ÓÒÏÂ½Ç
			{
				if(num[i][j]<num[i][j-1])//×ó±ß
				{
					//temp2=weight[i][j]+1;/*+num[i][j-1];*/
					//weight[i][j-1]=temp2>weight[i][j-1]?temp2:weight[i][j-1];
					if(weight[i][j-1]<weight[i][j]+1)
					weight[i][j-1]=weight[i][j]+1;
				}
				else if(num[i][j]<num[i-1][j])//ÉÏ±ß
				{
					//temp3=weight[i][j]+1;/*+num[i-1][j];*/
					//weight[i-1][j]=temp3>weight[i-1][j]?temp3:weight[i-1][j];
					if(weight[i-1][j]<weight[i][j]+1)
					weight[i-1][j]=weight[i][j]+1;	
				}
				break;
			}
		}
	}


	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			if(weight[i][j]>max)
				max=weight[i][j];
	}



	cout<<max<<endl;

	getchar();
	getchar();





}