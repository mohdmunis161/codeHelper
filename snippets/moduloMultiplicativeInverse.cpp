#include<iostream>
using namespace std;

// O(p) version -> X belongs to [0, p)
// int MMI(int N, int p) {
//     for(int X = 0; X < p; X = X + 1) {
//         // Multiply by 1LL first so the N*X calculation doesn't overflow!
//         if((1LL * N * X) % p == 1) return X;
//     } 
//     return -1;
// }



// // O(log(p)) version -> Fermat's little theorm
// Finds the Greatest Common Divisor (GCD).
// We need this to check if an inverse is even mathematically possible.
long long int gcd(long long int a, long long int b) {
    a = abs(a);
    b = abs(b);
    
    // Keep taking the remainder until it hits 0
    while (b != 0) {
        a %= b;
        swap(a, b); 
    }
    return a;
}

// Calculates (base^power) % mod insanely fast.
// Applying the modulo at every single step stops the numbers from overflowing 64-bit limits.
long long int modularExp(long long int base, long long int power, long long int mod) {
    long long int res = 1;
    
    if (power < 0) return 0; // Safety catch for negative exponents
    
    base %= mod; // Shrink the base right away just in case it's huge
    
    while (power > 0) {
        // If the power is odd, multiply it into our running total
        if (power % 2 != 0) { 
            res = (res * base) % mod;
        }
        
        // Square the base, cut the power in half, and keep going
        base = (base * base) % mod;
        power /= 2; 
    }
    
    return res;
}

// Calculates the Modular Multiplicative Inverse (MMI) of N modulo p.
// IMPORTANT: This specific trick (Fermat's Little Theorem) only works if 'p' is a prime number!
long long int MMI(long long int N, long long int p) {
    
    // The inverse only exists if N and p share no common factors (GCD is 1)
    if (gcd(N, p) == 1) {
        
        // Fermat's math magic: the inverse is exactly N^(p-2) modulo p
        return modularExp(N, p - 2, p);
    }

    // Return -1 as an error code if no inverse exists
    return -1;
}

int main() {
    // Fast I/O: Tells C++ to skip syncing with C-style printing for a speed boost
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int N, p;
    
    // Wait for the user to type two numbers
    if (cin >> N >> p) {
        long long int inverse = MMI(N, p);
        
        if (inverse != -1) {
            cout << inverse << "\n";
        } else {
            // Added a friendly error message so the user isn't just staring at "-1"
            cout << "No inverse exists (N and p share common factors)\n";
        }
    }
    
    return 0;
}