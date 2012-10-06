//#include <stdio.h> 
//void main() 
//{
//	int i,j,n,m; 
//	int x,sum=0;
//	while (scanf("%d",&n)==1)
//	{
//		for (j=1;j<=n;j++) 
//		{   scanf("%d",&m); 
//
//		for (i=1;i<=m;i++){
//			scanf("%d",&x);
//			sum+=x;} 
//		printf("%d\n\n",sum); 
//		sum=0; 
//		} 
//	} 
//}
#include <iostream>
using namespace std;
void main()
{
	int m, n, sum, x;
	cin>>m;
	while (m>0)
	{
		cin>>n;
		sum=0;
		while (n>0)
		{
			cin>>x;
			sum+=x;
			n--;
		}
		cout<<sum;
		if (m>1)
			cout<<"\n\n";
		m--;
	}
	//getchar();
	//getchar();
}