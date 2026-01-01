#include<bits/stdc++.h>
using namespace std;

const int _max=1000000;
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

int countDivs(int n) {
        if(n==1) return 1;
        int count=1; 
        while(n>1) {
                if(primeFac[n]!=-1) {
                        int pf=primeFac[n];
                        int p=0;
                        while(n%pf==0) {
                                p++;
                                n/=pf;
                        }
                        count=count*(p+1);
                } else {
                        n=1;
                        count=count*(1+1);
                }
        }
        return count;
}
int main() {
        sieve();
        int n;
        cin>>n;
        while(n--) {
                int x;
                cin>>x;
                cout<<countDivs(x)<<endl;
        }
}

