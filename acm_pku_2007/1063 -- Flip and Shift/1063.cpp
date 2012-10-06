#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    const int MAX = 32;
    bool a[MAX];
    int testCase, n, i, odd, even;

    scanf("%d", &testCase);
    while(testCase > 0)
    {
        testCase--;
        
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        if(n % 2 == 0)
        {
            odd = even = 0;
            for(i=0; i<n; i++)
            {
                if(a[i])
                {
                    if(i % 2 == 0)
                        even++;
                    else
                        odd++;
                }
            }
            if(abs(even-odd) <= 1)
                printf("YES\n");
            else
                printf("NO\n");
        }else
            printf("YES\n");

    
    }
    return 0;
}