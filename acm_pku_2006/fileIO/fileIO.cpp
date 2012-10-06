#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a, b;
    FILE*  file = freopen( "a.txt", "r", stdin);
    while ( scanf("%d %d", &a, &b) > 0 )
       printf( "%d\n" , a+b );
    fclose(file);
	int i;
	do{
	cin>>i;
	}while(i>0);
    return 0;
}
