#include <iostream>
#include <cmath>   // For std::abs
#include <utility> // For std::swap

using namespace std;

// 1. Use long long to handle numbers up to ~9 x 10^18
long long int gcd(long long int a, long long int b) {
    // 2. GCD is mathematically positive. std::abs handles negative inputs safely.
    a = abs(a);
    b = abs(b);
    
    // 3. Iterative approach completely eliminates recursion stack overhead
    while (b != 0) {
        a %= b;
        swap(a, b); // Clean, built-in way to shift variables without a 'temp'
    }
    
    return a;
}

int main() {
    // 4. Fast I/O for competitive programming environments
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int a, b;
    
    // Safely check if inputs were actually received before processing
    if (cin >> a >> b) {
        cout << gcd(a, b) << "\n"; // "\n" is faster than endl
    }
    
    return 0;
}