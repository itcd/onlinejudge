#include <iostream>
#include <cmath>
using namespace std;

#define N 100000000
#define SIZE ((N+31)/32)
int sieve[SIZE];

int main(){
	int k=N-1;
	int prime=2;
	int count=0;
	int lastfive[5], firstfive[5];
	sieve[0]=0xFFFFFFFC;

	for (int i=1;i<SIZE;i++){
		sieve[i]=0xFFFFFFFF;
	}
	while (prime <N){

		for (int j=prime+prime; j<N;j+=prime){
			sieve[j/32] &= ~(1 << (j % 32));
		}

		prime=prime+1;

		while ((sieve[prime/32] & (1 << (prime % 32))) == 0)
		{	
			prime++;
		}

	}

	while (count < 5)
	{	
		if ((sieve[k/32] & (1 << (k % 32))) > 0)
		{
			lastfive[count]=k;
			count++;
		}
		k--;
	}

	cout<<"The first 5 of the primes are:"<<endl;
	for(int i=0; i<5; i++)
		cout<<firstfive[i]<<endl;
	cout<<"The last 5 of the primes are:"<<endl;
	for(int i=0; i<5; i++)
		cout<<lastfive[i]<<endl;

	return 0;
}
