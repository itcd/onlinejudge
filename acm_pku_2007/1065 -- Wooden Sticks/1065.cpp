#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stick
{
    int l, w;
};

bool l_less(Stick s1, Stick s2)
{
    return s1.l < s2.l;
}

bool stick_less(Stick s1, Stick s2)
{
    return s1.l <= s2.l && s1.w <= s2.w;
}

int main()
{
    const int MAX = 5120;
    Stick v[MAX];
    Stick countV[MAX];
    int i, j, n, count, testCase;

    scanf("%d", &testCase);
    while(testCase > 0)
    {
        testCase--;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d", &v[i].l, &v[i].w);
        }
        sort(v, v+n, l_less);
        //for(i=0; i<n; i++)
        //{
        //    printf("%d,%d\n", v[i].l, v[i].w);
        //}

        count = 0;
        countV[count] = v[count];
        count++;
        for(i=1; i<n; i++)
        {
            for(j=0; j<count; j++)
            {
                if(stick_less(countV[j], v[i]))
                {
                    countV[j] = v[i];
                    break;
                }
            }
            if(j >= count)
            {
                countV[count] = v[i];
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}