/*
1088 -- ��ѩ
Time Limit:1000MS  Memory Limit:65536K
Total Submit:5327 Accepted:1549 

Description
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 


1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����

Input
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��

Output
��������ĳ��ȡ�

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

struct pos//���һ��2ά����stage�����λ��
{
	int i;
	int j;
};

const int maxSize = 100;
int stage[maxSize][maxSize];//��Ż�ѩ���߶����ݵ�����
int length[maxSize][maxSize];//·������
bool unused[maxSize][maxSize];

bool smaller(pos  a, pos  b)
{
	return stage[a.i][a.j]<stage[b.i][b.j];
}

void findPath(int i, int j, int r, int c, int &len, int &maxLen)//����i, jλ�õ��·����len:��ǰ���ȣ�maxLen:��󳤶�
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
	pos index[maxSize*maxSize];//��Ű��߶������ŵ������±�

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
	sort(index, index+r*c, smaller);//����λ�õĸ߶��ɵ͵�������

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
