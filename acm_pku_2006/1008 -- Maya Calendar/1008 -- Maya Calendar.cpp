#include<stdio.h>
#include<string.h>
//#include<iostream>
//#include<string>
//using namespace std;

void main()
{
	char month1[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	char month2[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

	int day, month, year, total, n, i;
	char s[10];
	scanf("%d", &n);
	printf("%d\n", n);
	for(i=0; i<n; i++)
	{
		scanf("%d. %s %d", &day, s, &year);
		for(month=0; month<19; month++)
			if(strcmp(s, month1[month])==0)
				break;
		total=year*365+month*20+day;
		printf("%d %s %d\n", total%13+1, month2[total%20], total/260);
	}

	//getchar();
	//getchar();
}