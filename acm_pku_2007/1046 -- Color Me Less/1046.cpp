#include <iostream>
#include <stdio.h>
using namespace std;

struct Color{
int r, g, b;
};

inline int getDistance(Color c1, Color c2)
{
    int dr = c2.r-c1.r, dg = c2.g-c1.g, db = c2.b-c1.b;
    return dr*dr + dg*dg + db*db;
}

inline void print(Color c1, Color c2)
{
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n", c1.r, c1.g, c1.b, c2.r, c2.g, c2.b);
}

int main()
{
    const int N = 16;
    Color set[N];
    Color check[1024];
    int i, j, min, minIndex, temp, r, g, b;
    int count = 0;
    for(i=0; i<N; i++)
        scanf("%d%d%d", &set[i].r, &set[i].g, &set[i].b);
    while(true)
    {
        scanf("%d%d%d", &r, &g, &b);
        if(r>=0 && g>=0 && b>=0)
        {
            check[count].r = r;
            check[count].g = g;
            check[count].b = b;

            minIndex = 0;
            min = getDistance(check[count], set[minIndex]);
            for(j=1; j<N; j++)
            {
                temp = getDistance(check[count], set[j]);
                if(temp < min)
                {
                    min = temp;
                    minIndex = j;
                }
            }
            print(check[count], set[minIndex]);
            count++;
        }else
            break;
    }

    //for(i=0; i<N; i++)
    //    printf("(%d,%d,%d)\n", set[i].r, set[i].g, set[i].b);
    //cout<<endl;
    //for(i=0; i<count; i++)
    //    printf("(%d,%d,%d)\n", check[i].r, check[i].g, check[i].b);

    return 0;
}