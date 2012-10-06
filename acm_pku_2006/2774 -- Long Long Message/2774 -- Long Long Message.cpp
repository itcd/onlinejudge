#include<iostream>
#include <string.h> 
#include <stdio.h> 
using namespace std;

inline int longestSubStr(char *str1, char *str2)
{
	int len1 = strlen(str1), len2 = strlen(str2);
	int i, j, max = 0;
	int match[100000] = {0};
	//memset(match, 0, len2*sizeof(int));

	for(i=0; i<len1; i++)
	{
		for(j=len2-1; j>0; j--)
		{
			if(str1[i] == str2[j])
			{
				match[j] = match[j-1] + 1;
				if(max < match[j])
					max = match[j];
			}
			else
				match[j] = 0;
		}
		//match[0] = (str1[i] == str2[0]) ? 1 : 0;
		if(str1[i] == str2[0])
		{
			match[0] = 1;
			if(max < match[j])
				max = match[j];
		}else
			match[0] = 0;
	}
	return max;
}

int main()
{
	char s1[100000], s2[100000];
	scanf("%s%s", s1, s2);
	printf("%d", longestSubStr(s1, s2));
	//getchar();
	//getchar();
	return 0;
}
