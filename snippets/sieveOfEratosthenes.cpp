#include <iostream>
#include <vector>

using namespace std;

void createSieve(vector<bool>& sieve) {
    int N = sieve.size() - 1;
    sieve[0] = sieve[1] = false;
    
    // Start at i = 2 (the first prime)
    for(int i = 2; i * i <= N; i++) {
        if(sieve[i]) {
            // Use 1LL to prevent potential integer overflow if N is very large
            for(long long j = 1LL * i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    // Fast I/O for handling large numbers of queries efficiently
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 1e7; // 10^7. Change to 1e6 if you meant 10^6.
    
    // vector<bool> is much more memory-efficient than vector<int>
    vector<bool> sieve(N + 1, true);
    createSieve(sieve);

    int q;
    if (cin >> q) {
        while (q--) {
            int x;
            cin >> x;
            
            // Bounds check to prevent segmentation faults
            if (x >= 0 && x <= N) {
                cout << sieve[x] << "\n"; // "\n" is faster than endl
            } else {
                cout << "Out of bounds\n";
            }
        }
    }
    return 0;
}