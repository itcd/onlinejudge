#include <iostream>

using namespace std;

int main()
{
	const int MAX = 10240;
	char p[MAX*2];
	int num[MAX];
	int weight[MAX*2];
	int n, i, j, k, pi, wi, times;

	cin>>times;
	while(times > 0)
	{
		times--;

		cin>>n;
		pi=0;
		for(i=0; i<n; i++)
		{
			cin>>num[i];

			if(i>0)
				k = num[i] - num[i-1];
			else
				k = num[i];

			for(j=0; j<k; j++)
			{
				p[pi] = '(';
				pi++;
			}
			p[pi] = ')';
			pi++;
		}

		for(i=0; i<pi; i++)
			cout<<p[i]<<ends;
		cout<<endl;

		wi = 0;
		weight[0] = 0;
		for(i=0; i<pi; i++)
		{
			if(p[i] == '(')
				weight[i+1] = weight[i] + 1;
			else
				weight[i+1] = weight[i] - 1;
		}

		for(i=0; i<pi+1; i++)
			cout<<weight[i]<<ends;
		cout<<endl;

		int begin, end, count;
		for(i=0; i<pi; i++)
		{
			if(p[i] == ')')
			{		
				end = i;
				begin = i-1;
				while(weight[begin]>=weight[end])
				{
					begin--;
				}

				count = 0;
				for(j=begin; j<=end; j++)
				{
					if(p[j] == ')')
						count++;
				}
				cout<<count<<ends;
			}
		}
		cout<<endl;

	}

	return 0;
}