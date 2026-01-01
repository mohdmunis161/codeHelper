int _max=3000;
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

int primeFacCount(int n) {
        if(n==0||n==1) return 0;
        int pfCount=0;
        while(n>1) {
                if(primeFac[n]!=-1) {
                        pfCount++;
                        int pf=primeFac[n];
                        while(n%pf==0) n/=pf;
                } else {
                        pfCount++;
                        n=1;
                }
        }

        return pfCount;
}

