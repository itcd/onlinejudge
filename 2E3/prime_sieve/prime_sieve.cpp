#include <iostream>
#include <cmath>
#include <ctime>
#include <stack>
using namespace std;

//#define N 1000000000				// size of sieve used 
#define N LONG_MAX / 2				// size of sieve used 
#define SIZE ((N+31)/32)				//32 bits per integer hard coded
int sieve[SIZE];							//array of bits

int main(){
	sieve[0] = 0xFFFFFFFC;
	for (int i=1; i<SIZE; i++)
	{
		sieve[i] = 0xFFFFFFFF;
	}

	cout<<hex<<sieve[0]<<endl;
	cout<<hex<<sieve[1]<<endl;

	int prime_number = 2;
	int n;
	cout<<"Please enter an integer between 1 and "<<dec<<N<<endl;
	cin>>n;

	auto t1 = clock();

	//while (prime_number < sqrt(n))
	int n_sqrt = (int)(sqrt(n) + 1e-6);
	while (prime_number <= n_sqrt)
	{
		for (int i=prime_number+prime_number; i<n; i+=prime_number)
		{
			sieve[i/32] &= ~(1 << (i % 32));
		}
		do 
		{
			prime_number++;
		} while ((sieve[prime_number/32] & (1 << (prime_number % 32))) == 0);
	}

	auto t2 = clock();

	cout<<hex<<sieve[0]<<endl;
	cout<<hex<<sieve[1]<<endl;

	int count = 0;
	for (int i=0; i<n; i++)
	{
		if ((sieve[i/32] & (1 << (i % 32))) > 0)
		{
			cout<<dec<<i<<"\t";
			count++;
			if (count >= 5)
			{
				cout<<endl;
				break;
			}
		}
	}
	
	count = 0;
	stack<int> s;
	for (int i=n-1; i>=0; i--)
	{
		if ((sieve[i/32] & (1 << (i % 32))) > 0)
		{
			s.push(i);
			count++;
			if (count >= 5)
			{
				break;
			}
		}
	}

	while (!s.empty())
	{
		cout<<s.top()<<"\t";
		s.pop();
	}
	cout<<endl;

	cout<<"It took "<<t2-t1<<" ticks i.e. "<<(t2-t1)/(float)CLOCKS_PER_SEC<<" seconds."<<endl;

	return 0;
}
