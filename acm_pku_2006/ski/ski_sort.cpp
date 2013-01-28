/*
1088 -- 滑雪
Time Limit:1000MS  Memory Limit:65536K
Total Submit:5327 Accepted:1549 

Description
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 


1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

Input
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

Output
输出最长区域的长度。

Sample Input


5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9


Sample Output


25

Source
Don't know
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct pos//存放一个2维数组stage里面的位置
{
	int i;
	int j;
};

const int maxSize = 100;
int stage[maxSize][maxSize];//存放滑雪场高度数据的数组
int length[maxSize][maxSize];//路径长度
bool unused[maxSize][maxSize];

bool smaller(pos  a, pos  b)
{
	return stage[a.i][a.j]<stage[b.i][b.j];
}

void findPath(int i, int j, int r, int c, int &len, int &maxLen)//查找i, j位置的最长路径，len:当前长度，maxLen:最大长度
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
				findPath(i+a[k][0], j+a[k][1], r, c, len, maxLen);
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
			maxLen=len;
}

void main()
{
	int r, c, i, j;//, k;
	int len, maxLength;
	pos index[maxSize*maxSize];//存放按高度升序排的序列下标

	cin>>r>>c;
	for(i=0; i<r; i++)//read data from input
		for(j=0; j<c; j++)
		{
			unused[i][j]=true;
			length[i][j]=1;
			cin>>stage[i][j];
			index[i*c+j].i=i;
			index[i*c+j].j=j;
		}
	sort(index, index+r*c, smaller);//根据位置的高度由低到高排序

	maxLength=1;
	for(i=0; i<r*c; i++)//calculate out all the lengths
	{
		if(unused[index[i].i][index[i].j])
		{
				len=1;
				findPath(index[i].i, index[i].j, r, c, len, length[index[i].i][index[i].j]);	
				if(length[index[i].i][index[i].j]>maxLength)
					maxLength=length[index[i].i][index[i].j];		
		}
	}

	for(i=0; i<r; i++)//output all the lengths
	{
		for(j=0; j<c; j++)
		{
			cout<<length[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<maxLength<<endl;

	getchar();
	getchar();
}
