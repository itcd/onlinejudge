#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;

const int n=12;//Ӳ����
const int m=3;//
char s1[m][n], s2[m][n], s3[m][n];

int balance(char *s)
{
	if(strcmp(s, "up")==0)//��
		return -1;
	if(strcmp(s, "down")==0)//��
		return 1;
	return 0;//ƽ
}

void compare(int l, int possible[])//Ҫ������Ӳ����l, Ӳ�ҿ���������:0������1���ˣ�2������3����
{
	int i, len=(int)strlen(s1[l]);
	char *p;
	for(i=0; i<len; i++)
	{
		p=strchr(s1[l], s2[l][i]);
		if(p)
			possible[s2[l][i]-'A']=2;
	}
	if(balance(s3[l])==0)
		for(i=0; i<len; i++)
		{
			possible[s1[l][i]-'A']=2;
			possible[s2[l][i]-'A']=2;
		}
	if(balance(s3[l])<0)//��������
		for(i=0; i<len; i++)
		{
			if(possible[s1[l][i]-'A']==0)
				possible[s1[l][i]-'A']=3;
			if(possible[s1[l][i]-'A']==1)
				possible[s1[l][i]-'A']=2;//ì�ܣ��������

			if(possible[s2[l][i]-'A']==0)
				possible[s2[l][i]-'A']=1;
			if(possible[s2[l][i]-'A']==3)
				possible[s2[l][i]-'A']=2;//ì�ܣ��������
		}
	if(balance(s3[l])>0)//��������
		for(i=0; i<len; i++)
		{
			if(possible[s1[l][i]-'A']==0)
				possible[s1[l][i]-'A']=1;
			if(possible[s1[l][i]-'A']==3)
				possible[s1[l][i]-'A']=2;//ì�ܣ��������

			if(possible[s2[l][i]-'A']==0)
				possible[s2[l][i]-'A']=3;
			if(possible[s2[l][i]-'A']==1)
				possible[s2[l][i]-'A']=2;//ì�ܣ��������
		}
}

//void compare2(int l1, int l2, int possible[])//Ҫ�Ƚϵ�Ӳ����1,2//������:0������1���ˣ�2������3����
//{
//	//������:0������1���ˣ�2������3����
//	int i, j;
//	char *p;
//	for(i=0; i<n; i++)
//		possible[i]=0;
//	if(balance(s3[l1])>balance(s3[l2]))
//	{
//		i=l1;
//		l1=l2
//		l2=i;
//	}
//	if(balance(s3[l1])==0)
//	{
//		for(i=0; i<num; i++)
//			possible[s1[l1][i]-'A']=2;
//	}
//	if(balance(s3[l2])==0)
//	{
//		for(i=0; i<num; i++)
//			possible[s1[l2][i]-'A']=2;
//	}
//
//	if(balance(s3[l1])<0)
//	{
//		for(i=0; i<num; i++)
//		{
//			p=strchr(s1[l1], s1[l2][i]);
//			if(p)
//			{
//				if(possible[s1[l2][i]-'A']==0)
//					possible[s1[l2][i]-'A']=3;//�������
//				if(possible[s1[l2][i]-'A']==1)
//					possible[s1[l2][i]-'A']=2;//ì�ܣ��������
//			}
//			//p=strchr(s2[l1], s2[l2][i]);
//			//if(p)
//			//	possible[s2[l2][i]-'A']=1;//�ұ�����				
//		}		
//	if(strcmp(s3[l1], "down")==0)
//	{
//		for(i=0; i<num; i++)
//		{
//			p=strchr(s1[l1], s1[l2][i]);
//			if(p && possible[s1[l2][i]-'A']==0)
//				possible[s1[l2][i]-'A']=1;//�������
//			//p=strchr(s2[l1], s2[l2][i]);//
//			//if(p)
//			//	possible[s2[l2][i]-'A']=3;//�ұ�����				
//		}		
//	}
//	if(balance(s3[l1])==0)
//		for(i=0; i<num; i++)
//		{
//			possible[s1[l1][i]-'A']=2;
//			possible[s2[l1][i]-'A']=2;
//			//possible[s1[l2][i]-'A']=2;
//			//possible[s2[l2][i]-'A']=2;
//		}
//
//
//	//if(strcmp(s3[l1], s3[l2])==0)//���
//	//{
//	//	if(strcmp(s3[l1], "up")==0)
//	//	{
//	//		for(i=0; i<num; i++)
//	//		{
//	//			p=strchr(s1[l1], s1[l2][i]);
//	//			if(p)
//	//				possible[s1[l2][i]-'A']=3;//�������
//	//			
//	//			p=strchr(s2[l1], s2[l2][i]);
//	//			if(p)
//	//				possible[s2[l2][i]-'A']=1;//�ұ�����				
//	//		}		
//	//	if(strcmp(s3[l1], "down")==0)
//	//	{
//	//		for(i=0; i<num; i++)
//	//		{
//	//			p=strchr(s1[l1], s1[l2][i]);
//	//			if(p)
//	//				possible[s1[l2][i]-'A']=1;//�������
//	//			
//	//			p=strchr(s2[l1], s2[l2][i]);//
//	//			if(p)
//	//				possible[s2[l2][i]-'A']=3;//�ұ�����				
//	//		}		
//	//	}
//	//	if(strcmp(s3[l1], "even")==0)
//	//		for(i=0; i<num; i++)
//	//		{
//	//			possible[s1[l1][i]-'A']=2;
//	//			possible[s2[l1][i]-'A']=2;
//	//			possible[s1[l2][i]-'A']=2;
//	//			possible[s2[l2][i]-'A']=2;
//	//		}
//	//}else
//	//{
//	//	if(strcmp(s3[l1], "up")==0 && strcmp(s3[l2], "down")==0)
//	//	{
//	//		for(i=0; i<num; i++)
//	//		{
//	//			p=strchr(s1[l1], s1[l2][i]);
//	//			if(p)
//	//				possible[s1[l2][i]-'A']=3;//�������
//	//			
//	//			p=strchr(s2[l1], s2[l2][i]);
//	//			if(p)
//	//				possible[s2[l2][i]-'A']=1;//�ұ�����				
//	//		}		
//	//	if(strcmp(s3[l1], "down")==0 && s3[l2], "up")==0)
//	//	{
//	//		for(i=0; i<num; i++)
//	//		{
//	//			p=strchr(s1[l1], s1[l2][i]);
//	//			if(p)
//	//				possible[s1[l2][i]-'A']=1;//�������
//	//			
//	//			p=strchr(s2[l1], s2[l2][i]);//
//	//			if(p)
//	//				possible[s2[l2][i]-'A']=3;//�ұ�����				
//	//		}		
//	//	}
//	//	if(strcmp(s3[l1], "even")==0)
//	//		for(i=0; i<num; i++)
//	//		{
//	//			possible[s1[l1][i]-'A']=2;
//	//			possible[s2[l1][i]-'A']=2;
//	//			possible[s1[l2][i]-'A']=2;
//	//			possible[s2[l2][i]-'A']=2;
//	//		}
//	//}
//}

void main()
{
	int i, j, times;
	int weight[n]={0};//0������1���ˣ�2������3����
	int possible1[n]={0}, possible2[n]={0}, possible3[n]={0};
	int differ[m]={0};

	scanf("%d", &times);
	while(times>0)
	{
		for(i=0; i<m; i++)
			scanf("%s %s %s", s1[i], s2[i], s3[i]);
		//for(i=0; i<m; i++)
		//	printf("%s %s %s\n", s1[i], s2[i], s3[i]);

		j=0;
		for(i=0; i<m; i++)
		{
			compare(i, weight);
			if(balance(s3[i])!=0)
			{
				differ[j]=i;
				j++;
			}
		}

		if(j>1)
		{
			for(i=0; i<j; i++)
			{
				compare(i, weight);
			}
		}

		//for(i=0; i<n; i++)
		//	printf("%c:%d\t", 'A'+i, weight[i]);

		for(i=0; i<n; i++)
		{
			if(weight[i]==1)
			{
				printf("%c is the counterfeit coin and it is light.\n", 'A'+i);
				break;
			}
			if(weight[i]==3)
			{
				printf("%c is the counterfeit coin and it is heavy.\n", 'A'+i);
				break;
			}
		}
	}

	getchar();
	getchar();

}