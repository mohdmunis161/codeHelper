#include<iostream>
#include<vector>
using namespace std;

void createSieve(vector<int>& sieve) {
    int N = sieve.size() - 1;
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i <= N; i++) {
        if(sieve[i] == 1) {
            for(int j = i*i; j <= N; j+=i) {
                sieve[j] = 0;
            }
        }
    }
}
int main() {
    int N = 1e+6;
    vector<bool> sieve(N+1, 1);
    createSieve(sieve);


    int  q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << sieve[x] << endl;
    }
}