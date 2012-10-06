#include<iostream>

#include <vector>

using namespace std;

int length;
int NumLStick;
int NumStick;
bool used[64];
short int stick[64];
//char usedTable[100][64];
//bool close[100];
short int close[64][50];

class result
{
	bool used[64];
	bool value;
	result(bool used[], Num)
	{
	}
};

vector <result> vec_result;

bool search(int ns,int cl)
{
	if((close[ns][cl] == 1)&&(ns < NumLStick / 3))
	{
		return 1;
	}
	else if((close[ns][cl] == -1)&&(ns < NumLStick / 3))
	{
		return 0;
	}

	for(int i = 0;i < NumStick;i++)
	{
		if(!used[i])
		{
			int currentLength = cl + stick[i];
			if(currentLength == length)
			{
				used[i] = 1;
				if(ns + 1== NumLStick - 1)
				{
					return 1;
				}
				if(search(ns + 1,0) == 1)
				{
					close[ns + 1][0] = 1;
					return 1;
				}
				else
				{
					used[i] = 0;
					continue;
				}
			}
			else if(currentLength < length)
			{
				used[i] = 1;
				if(search(ns,currentLength) == 1)
				{
					result temp;
					vec_result.push_back();
					return 1;
				}
				else
				{
					used[i] = 0;
					continue;
				}
			}
		}
	}
	close[ns][cl] = -1;
	return 0;
}

void main()
{
	int n;
	while(cin>>n)
	{
		if(n == 0)
		{
			break;
		}
		int max = 0;
		int total = 0;
		NumStick = 0;
		int i;
		for(i = 0;i < n;i++)
		{
			cin>>stick[i];
			NumStick++;
			if(stick[i] > max)
			{
				max = stick[i];
			}
			total += stick[i];
		}

		for(i = max;i <= total;i++)
		{
			if(((float)total / (float)i) != (int)(total / i))
			{
				continue;
			}

			memset(close,0,sizeof(close));

			memset(used,0,sizeof(used));

			length = i;
			NumLStick = total / i;

			if(NumLStick == 1)
			{
				cout<<length<<endl;
				break;
			}

			if(search(0,0) == 1)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	//return 0;
} 













#include<iostream>

#include <vector>
#include <set>

using namespace std;

int length;
int NumLStick;
int NumStick;

multiset <char, greater<char> > sss;

multiset <char, greater<char> > sssStore[100];
bool returnValue[100];
int NumSetStore;

bool search(int ns,int cl);

void main()
{
	multiset <char, greater<char> > Tsss;

	short int result[1000];
	int resultNum = 0;

	int n;
	while(cin>>n)
	{
		if(n == 0)
		{
			break;
		}
		int max = 0;
		int total = 0;
		NumStick = 0;
		//pair< set<int>::iterator, bool > pr;
		//StickTypy newStick;
		//NumType = 0;
		int p;
		int i;
		for(i = 0;i < n;i++)
		{
			cin>>p;
	
			sss.insert(static_cast <char>(p));
			
			NumStick++;

			total += p;
		}

		max = *sss.begin();

		for(i = max;i <= total;i++)
		{
			if(((float)total / (float)i) != (int)(total / i))
			{
				continue;
			}

			NumSetStore = 0;

			length = i;
			NumLStick = total / i;

			if(NumLStick == 1)
			{
				//cout<<length<<endl;
				result[resultNum] = length;
				resultNum++;
				break;
			}

			if(search(0,0) == 1)
			{
				//cout<<i<<endl;
				result[resultNum] = i;
				resultNum++;
				break;
			}
		}
	}
	for(int t = 0;t < resultNum;t++)
	{
		cout<<result[t]<<endl;
	}
	//return 0;
} 

bool search(int ns,int cl)
{
	for(int j = 0;j < NumSetStore;j++)
	{
		if(sss == sssStore[j])
		{
			return returnValue[j];
		}
	}

	multiset <char, greater<char> >::iterator ms_Iter;
	char current = 100;

	for(ms_Iter = sss.begin(); ms_Iter != sss.end();ms_Iter++)
	{
		if(*ms_Iter != current)
		{
			int currentLength = cl + *ms_Iter;
			current = *ms_Iter;
			if(currentLength == length)
			{
				sss.erase(ms_Iter);

				if(ns + 1 == NumLStick - 1)
				{
					return 1;
				}

				if(search(ns + 1,0) == 1)
				{
					/*
					if(NumSetStore < 100)
					{
						sssStore[NumSetStore] = sss;
						returnValue[NumSetStore] = 1;
						NumSetStore++;
					}
					*/
					return 1;
				}        
				else
				{
					sss.insert(current);
					//used[i] = 0;
					continue;
				}
			}
			else if(currentLength < length)
			{
				sss.erase(ms_Iter);
				if(search(ns,currentLength) == 1)
				{
					/*
					if(NumSetStore < 100)
					{
						sssStore[NumSetStore] = sss;
						returnValue[NumSetStore] = 1;
						NumSetStore++;
					}
					*/
					return 1;
				}
				else
				{
					sss.insert(current);
					continue;
				}
			}
		}
	}

	if(NumSetStore < 100)
	{
		sssStore[NumSetStore] = sss;
		returnValue[NumSetStore] = 0;
		NumSetStore++;
	}
	return 0;
}















#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int length;
int NumLStick;
int NumStick;
short int used[64];
vector <int> stick;//[64];
//stick.reserve (64);

int search(int ns,int cl)
{
	int former = 100;
	for(int i = 0;i < NumStick;i++)
	{
		if(!used[i])
		{
			if(stick[i] == former)
			{
				continue;
			}

			former = stick[i];

			if(cl == 0)
			{
				if(ns == NumLStick - 1)
				{
					return 1;
				}

				used[i] = 1;
				if(stick[i] == length)
				{
					if(search(ns + 1,0) == 0)
					{
						used[i] = 0;
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else
				{
					if(search(ns,stick[i]) == 0)
					{
						used[i] = 0;
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}

			int currentLength = cl + stick[i];
			if(currentLength == length)
			{
				used[i] = 1;

				if(ns + 1 == NumLStick - 1)
				{
					return 1;
				}

				int retrunValue = search(ns + 1,0);

				if(retrunValue == 1)
				{
					return 1;
				}
				else if(retrunValue == 0)
				{
					used[i] = 0;
					continue;
				}
				else
				{
					//return -1;
				}
			}
			else if(currentLength < length)
			{
				used[i] = 1;
				int retrunValue = search(ns,currentLength);

				if(retrunValue == 1)
				{
					return 1;
				}
				else if(retrunValue == 0)
				{
					used[i] = 0;
					continue;
				}
				else
				{
					//return -1;
				}
			}
		}
	}
	return 0;
}

bool UDgreater ( int elem1, int elem2 )
{
   return elem1 > elem2;
}



int main()
{
	stick.reserve (64);
	int n;
	while(cin>>n)
	{
		if(n == 0)
		{
			break;
		}
		int max = 0;
		int total = 0;
		NumStick = 0;
		short int temp;
		stick.clear();
		int i;
		for(i = 0;i < n;i++)
		{
			cin>>temp;
			stick.push_back(temp);
			NumStick++;
			
			if(stick[i] > max)
			{
				max = stick[i];
			}
			total += stick[i];
			
		}

		sort( stick.begin( ), stick.end( ), UDgreater);

		for(i = max;i <= total;i++)
		{
			if(((float)total / (float)i) != (int)(total / i))
			{
				continue;
			}
			memset(used,0,sizeof(used));

			length = i;
			NumLStick = total / i;

			if(NumLStick == 1)
			{
				cout<<length<<endl;
				
				break;
			}

			if(search(0,0) == 1)
			{
				cout<<i<<endl;
				
				break;
			}
		}
	}
	
	return 0;
} 