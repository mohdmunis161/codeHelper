#include<bits/stdc++.h>
using namespace std;

const int _max=8000000;
vector<int> isPrime(_max+1, 1);
void sieve() {
	isPrime[0]=isPrime[1]=0;
	for(int i=2; i*i<=_max; i++) {
		if(isPrime[i]==1) {
			for(int j=i*i; j<=_max; j+=i) isPrime[j]=0; 
		}
	}
}

int nthPrime(int n) {
	int count=0;
	for(int i=0; i<=_max; i++) {
		if(isPrime[i]==1) count++;
		if(count==n) return i;
	}	
	return -1;
}
int main() {
	
	sieve();
	int n;
	cin>>n;
	cout<<nthPrime(n)<<endl;
}


