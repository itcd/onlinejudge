#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addStr(char *c1, int l1, char *c2, int l2, char *&c3, int &l3)
{
    int min, max;
    char *cmax;
    if(l1 < l2)
    {
        min = l1;
        max = l2;
        cmax = c2;
    }else
    {
        min = l2;
        max = l1;
        cmax = c1;
    }
    c3 = new char[max+1];
    l3 = 0;
    int carry = 0;
    int i, bit;
    const int d0 = '0' + '0';
    for(i=0; i<min; i++)
    {
        if(carry > 0 )
            bit = c1[l1-i-1] + c2[l2-i-1] - d0 + carry;
        else
            bit = c1[l1-i-1] + c2[l2-i-1] - d0;
        carry = bit / 10;
        c3[i] = (char)((bit % 10) + '0');
        l3++;
    }
    if(max > min)
    {
        for(i=min; i<max; i++)
        {
            if(carry > 0 )
                bit = cmax[max-i-1] - '0' + carry;
            else
                bit = cmax[max-i-1] - '0';
            carry = bit / 10;
            c3[i] = (char)((bit % 10) + '0');
            l3++;
        }
    }
    if(carry > 0)
    {
        c3[l3] = (char)(carry + '0');
        l3++;
    }
    c3[l3] = '\0';
    c3 = strrev(c3);
}

char *getLast(char *c, int l)
{
    char *cc = new char[l+1];
    int i;
    const int dc = '9' + '0';
    for(i=0; i<l; i++)
    {
        cc[i] = (char)(dc - c[i]);
    }
    cc[l] = '\0';
    return cc;
}

inline void compare(char *c1, char *c2, char *c3)
{
    int r = strcmp(c1, c2);
    if(r == 0)
        printf("%s is cyclic\n", c3);
    else
        printf("%s is not cyclic\n", c3);
}

int main()
{
    int len, i, l3;
    char c[64];
    char *c3, *cLast;
    while(scanf("%s", c) > 0)
    {
        //printf("read:\t%s\n", c);
        len = strlen(c);

        c3 = c;
        l3 = len;
        for(i=0; i<len-1; i++)
        {
            addStr(c, len, c3, l3, c3, l3);
            //printf("%s\n", c3);
        }
        
        cLast = getLast(c, len);
        //printf("%s\n", cLast);
        compare(c3, cLast, c);
    }

    return 0;
}