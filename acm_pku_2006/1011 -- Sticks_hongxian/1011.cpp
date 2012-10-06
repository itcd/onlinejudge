#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

short len[64];
bool b[64];
short n,poslen,sticks;

bool Search(short stickno, short startno, short leftlen)
{
	if(stickno==sticks-1) return true;

	if( stickno>0 && !b[stickno-1] ) return false;

	for(int i=startno; i<n; i++)
	{
		if(!b[i])
		{
			if( (i>0)&&(!b[i-1]) && (len[i-1]==len[i])) continue;

			if(len[i]==leftlen)
			{
				b[i] = true;
				if (Search(stickno+1,0,poslen)) return true;
				b[i] = false;
			}
			else if(len[i]<leftlen)
			{
				int j = n-1;
				while(b[j])
					j--;

				if(len[i]+len[j]<=leftlen)
				{
					b[i] = true;
					if(Search(stickno,i+1,leftlen-len[i])) return true;
					b[i] = false;
				}
			}
		}
	}

	return false;
}

void main()
{
	short i,maxlen,totallen;
	cin>>n;
	while(n)
	{
		maxlen = totallen = 0;

		for(i=0; i<n; i++)
		{
			cin>>len[i];
			if(len[i]>50)
				len[i]=0;
			totallen += len[i];
			if(len[i]>maxlen)
				maxlen = len[i];
		}

		sort(&len[0],&len[n],greater<int>());
		i=0;
		while((i<n)&&(len[i]>0)) i++;
		n = i;

		for(poslen=maxlen; poslen<totallen; poslen++)
		{
			if(totallen%poslen) continue;

			memset(b,0,n*sizeof(bool));

			sticks = totallen / poslen;
			if(Search(0,0,poslen))
				break;
		}
		cout<<poslen<<endl;

		cin>>n;
	}
}

