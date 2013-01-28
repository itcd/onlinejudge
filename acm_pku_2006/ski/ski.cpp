#include<iostream>
using namespace std;

const int maxSize = 100;

void findPath(int stage[maxSize][maxSize], bool unused[maxSize][maxSize], int length[maxSize][maxSize], int i, int j, int r, int c, int &len, int &maxLen)
{
	static int a[4][2]={
	 0,  1,//right
	 0, -1,//left
	 1,  0,//down
	-1,  0};//up
	int k;
	bool end=true;

	for(k=0; k<4; k++)
	{
		if(i+a[k][0]>=0 && i+a[k][0]<r && j+a[k][1]>=0 && j+a[k][1]<c && stage[i][j]>stage[i+a[k][0]][j+a[k][1]])
		{
			if(end)
				end=false;

			if(unused[i+a[k][0]][j+a[k][1]])
			{
				unused[i+a[k][0]][j+a[k][1]]=false;
				len++;
				findPath(stage, unused, length, i+a[k][0], j+a[k][1], r, c, len, maxLen);
				len--;
			}else
			{
				len+=length[i+a[k][0]][j+a[k][1]];
				if(len>maxLen)
					maxLen=len;
				len-=length[i+a[k][0]][j+a[k][1]];
			}
	}
	}

	if(end && len>maxLen)
	{
			maxLen=len;
	}
}

void main()
{
	int r, c, i, j, k;
	int len, maxLength;
	int stage[maxSize][maxSize];//高度
	int length[maxSize][maxSize];//路径长度
	int index[maxSize*maxSize][2];//存放按高度升序排的序列下标
	bool unused[maxSize][maxSize];

	cin>>r>>c;

	for(i=0; i<r; i++)//read data from input
		for(j=0; j<c; j++)
		{
			unused[i][j]=true;
			length[i][j]=1;
			cin>>stage[i][j];
			index[i*c+j][0]=i;
			index[i*c+j][1]=j;
		}

	for(i=0; i<r*c-1; i++)//sort by height(upwards)
	{
		k=i;
		for(j=i+1; j<r*c; j++)
		{
			if(stage[index[j][0]][index[j][1]]<stage[index[k][0]][index[k][1]])
				k=j;
		}
		if(k!=i)
		{
			len=index[i][0];
			index[i][0]=index[k][0];
			index[k][0]=len;
			len=index[i][1];
			index[i][1]=index[k][1];
			index[k][1]=len;
		}
	}

	maxLength=1;

	for(i=0; i<r*c; i++)//calculate out all the lengths
	{
		if(unused[index[i][0]][index[i][1]])
		{
				len=1;
				findPath(stage, unused, length, index[i][0], index[i][1], r, c, len, length[index[i][0]][index[i][1]]);	
				if(length[index[i][0]][index[i][1]]>maxLength)
					maxLength=length[index[i][0]][index[i][1]];		
		}
	}

	//for(i=0; i<r; i++)//output all the lengths
	//{
	//	for(j=0; j<c; j++)
	//	{
	//		cout<<length[i][j]<<"\t";
	//	}
	//	cout<<endl;
	//}

	cout<<maxLength<<endl;

	//getchar();
	//getchar();
}