#include<bits/stdc++.h>
using namespace std;

const int _max=500000;
vector<int> primeFac(_max+1, -1);

void sieve() {
	primeFac[0]=primeFac[1]=0;
	for(int i=2; i*i<=_max; i++) {
		if(primeFac[i]==-1) {
			for(int j=i*i; j<=_max; j+=i) {
				if(primeFac[j]==-1) primeFac[j]=i;
			}
		}
	}
}


int binExp(int a, int n) {
	int res=1;
	while(n) {
		if(n%2){
			n--;
			res*=a;
		} else {
			n/=2;
			a*=a;
		}
	}
	return res;
}
int divSum(int n) {
	if(n==1) return 0;
	int N=n;
	int sum=1;
	while(n>1) {
		int pf;
		int p;
		if(primeFac[n]!=-1) {
			pf=primeFac[n];
			p=0;
			while(n%pf==0){
				p++;
				n/=pf;
			}
		} else {
			pf=n;
			p=1;
			n=1;
		}
		sum*=(binExp(pf, p+1)-1)/(pf-1);
	
	}

	return sum-N;
	
}

int main() {
	sieve();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<divSum(n)<<endl;
	}
	A
}
