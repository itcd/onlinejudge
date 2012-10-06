#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int N = 4;
struct Card
{
    int characteristic[N];
    char str[N+1];
};

/*
symbol  D O S
number  1 2 3
color   R G P
shading O F S
*/

int symbolToInt(char c)
{
    switch(c)
    {
    case 'D': return 1;
    case 'O': return 2;
    case 'S': return 4;
    default: return 0;
    }
}

int numberToInt(char c)
{
    switch(c)
    {
    case '1': return 1;
    case '2': return 2;
    case '3': return 4;
    default: return 0;
    }
}

int colorToInt(char c)
{
    switch(c)
    {
    case 'R': return 1;
    case 'G': return 2;
    case 'P': return 4;
    default: return 0;
    }
}

int shadingToInt(char c)
{
    switch(c)
    {
    case 'O': return 1;
    case 'F': return 2;
    case 'S': return 4;
    default: return 0;
    }
}

inline bool allSameOrDifferent(int a, int b, int c)
{
    /*
    100
    010
    001
    or=7 and=0, all different

    100
    100
    001
    or!=7 and=0

    100
    100
    100
    or!=7 and!=0, all the same
    */
    int or = a | b | c, and = a & b & c;
    if(or == 7 || and != 0)
        return true;
    else
        return false;
}

inline bool isSet(Card c1, Card c2, Card c3)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(!allSameOrDifferent(c1.characteristic[i], c2.characteristic[i], c3.characteristic[i]))
            return false;
    }
    return true;
}

int main()
{
    typedef int (*fp)(char c);//注意,这里不是声明函数指针,而是定义一个函数指针的类型,这个类型是自己定义的,类型名为fp  
    fp fun[N];
    fun[0] = symbolToInt;
    fun[1] = numberToInt;
    fun[2] = colorToInt;
    fun[3] = shadingToInt;

    Card cards[1024];
    char c[128];
    int i, j, k, m, amount = 0, count;
    bool loop;
    int len;

    do
    {
        loop = gets(c);
        len = strlen(c);
        if(loop && len == N)
        {
            for(i=0; i<N; i++)
            {
                cards[amount].characteristic[i] = fun[i](c[i]);
            }
            strcpy(cards[amount].str, c);
            amount++;
        }
        if(!loop || len != N)
        {
            if(amount > 0)
            {
                printf("CARDS: ");
                for(i=0; i<amount; i++)
                {
                    printf(" %s", cards[i].str);
                    //for(j=0; j<N; j++)
                    //    printf("\t%d", cards[i].characteristic[j]);
                    //printf("\n");
                }
                printf("\n");
                count = 0;
                for(i=0; i<amount-2; i++)
                {
                    for(j=i+1; j<amount-1; j++)
                    {
                        for(k=j+1; k<amount; k++)
                        {
                            //printf("%d\t%d\t%d\n", i, j, k);
                            if(isSet(cards[i], cards[j], cards[k]))
                            {
                                count++;
                                if(count > 1)
                                    printf("        %d.  %s %s %s\n", count, cards[i].str, cards[j].str, cards[k].str);
                                else
                                    printf("SETS:   %d.  %s %s %s\n", count, cards[i].str, cards[j].str, cards[k].str);
                            }
                        }
                    }
                }
                amount = 0;
                if(count == 0)
                    printf("SETS:   *** None Found ***\n");
                printf("\n");
            }      
        }
    }while(loop);

    return 0;
}