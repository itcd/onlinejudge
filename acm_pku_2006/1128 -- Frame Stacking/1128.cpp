#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

char a[32][32];
int h, w;
const int N = 5;
const char STAR = '*';
char list[] = {'A', 'B', 'C', 'D', 'E'};
int total[] = {12, 14, 10, 18, 24};
int x1__[N] = {-1, -1, -1, -1, -1};
int y1__[N] = {-1, -1, -1, -1, -1};
int x2__[N] = {-1, -1, -1, -1, -1};
int y2__[N] = {-1, -1, -1, -1, -1};
char result[N];
int ri = 1;


struct Node
{
    int index;
    int differ;
};

Node nodes[N];

bool less(Node n1, Node n2)
{
    return n1.differ < n2.differ;
}

void findBorder()
{
    int i, j, index;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            if(a[i][j]>='A' && a[i][j]<='E')
            {
                index = a[i][j] - 'A';
                if(x1__[index]<0 || j<x1__[index])
                    x1__[index] = j;
                if(y1__[index]<0 || i<y1__[index])
                    y1__[index] = i;
                if(x2__[index]<0 || j>x2__[index])
                    x2__[index] = j;
                if(y2__[index]<0 || i>y2__[index])
                    y2__[index] = i;
            }
        }
    }
}

int countLetterAmount(int index)
{
    int i, k, count = 0;
    char c = list[index];

    // top border
    k = y1__[index];
    for(i=x1__[index]; i<x2__[index]; i++)
        if(a[k][i]==c || a[k][i]==STAR)
            count++;

    // bottom border
    k = y2__[index];
    for(i=x1__[index]; i<x2__[index]; i++)
        if(a[k][i]==c || a[k][i]==STAR)
            count++;

    // left border
    k = x1__[index];
    for(i=y1__[index]+1; i<y2__[index]; i++)
        if(a[i][k]==c || a[i][k]==STAR)
            count++;

    // right border
    k = x2__[index];
    for(i=y1__[index]; i<=y2__[index]; i++)
        if(a[i][k]==c || a[i][k]==STAR)
            count++;

    return count;
}

void fillStar(int index)
{
    int i, k, count = 0;
    char c = list[index];

    // top border
    k = y1__[index];
    for(i=x1__[index]; i<x2__[index]; i++)
        if(a[k][i]==c)
            a[k][i] = STAR;

    // bottom border
    k = y2__[index];
    for(i=x1__[index]; i<x2__[index]; i++)
        if(a[k][i]==c)
            a[k][i]=STAR;

    // left border
    k = x1__[index];
    for(i=y1__[index]+1; i<y2__[index]; i++)
        if(a[i][k]==c)
            a[i][k]=STAR;

    // right border
    k = x2__[index];
    for(i=y1__[index]; i<=y2__[index]; i++)
        if(a[i][k]==c)
            a[i][k]=STAR;

    int j;
    for(i=0; i<N; i++)
    {
        if(nodes[i].differ > 0)
        {
            j = nodes[i].index;
            nodes[i].differ = total[j] - countLetterAmount(j);
            //cout<<list[j]<<"\tdiffer:"<<nodes[i].differ<<"\tamount:"<<countLetterAmount(j)<<"\ttotal:"<<total[j]<<endl;
        }
    }
}

void showAll()
{
    int i, j;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

//void search(int ri)
//{
//    int i;
//    if(ri < N)
//    {
//        for(i=1; i<N; i++)
//        {
//            if(nodes[i].differ == 0)
//            {
//                j = nodes[i].index;
//                result[ri] = list[j];
//                ri++;
//                fillStar(j);
//                showAll();
//                nodes[i].differ--;
//            }
//        }
//    }else
//    {
//        for(i=N-1; i>=0; i--)
//            cout<<result[i];
//        cout<<endl;
//    }
//}

int main()
{
    int i, j, count;
    char str[256];

    cin.getline(str, 80);
    h = atoi(str);

    while(h != 0)
    {
        cin.getline(str, 80);
        w = atoi(str);

        for(i=0; i<h; i++)
            cin>>a[i];;

        findBorder();
        //showAll();
        //for(i=0; i<N; i++)
        //    cout<<list[i]<<"\t"<<x1__[i]<<","<<y1__[i]<<"\t"<<x2__[i]<<","<<y2__[i]<<endl;

        for(i=0; i<N; i++)
        {
            nodes[i].index = i;
            nodes[i].differ = total[i] - countLetterAmount(i);
            //cout<<list[nodes[i].index]<<"\t"<<nodes[i].differ<<endl;
        }
        sort(nodes, nodes+N, less);
        //cout<<endl;
        //for(i=0; i<N; i++)
        //    cout<<list[nodes[i].index]<<"\t"<<nodes[i].differ<<endl;

        result[0] = list[nodes[0].index];
        ri = 1;
        fillStar(nodes[0].index);
        //showAll();

        while(ri < N)
        {
            for(i=1; i<N; i++)
            {
                if(nodes[i].differ == 0)
                {
                    j = nodes[i].index;
                    result[ri] = list[j];
                    ri++;
                    fillStar(j);
                    //showAll();
                    nodes[i].differ--;
                }
            }
        }

        for(i=N-1; i>=0; i--)
            cout<<result[i];
        cout<<endl;
        getchar();

        cin.getline(str, 80);
        h = atoi(str);
    }

    return 0;
}