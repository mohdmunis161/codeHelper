#include <iostream>
using namespace std;

long long int binaryExp(long long int A, int n) {
    long long int res = 1;
    
    // Safety check: if n is negative, standard integer logic fails
    if (n < 0) return 0; 
    
    while (n > 0) {
        // If n is odd (n % 2 != 0)
        if (n & 1) { 
            res = res * A;
        }
        // ALWAYS square A and halve n, regardless of whether n was odd or even.
        // Because integer division (or right-shift) rounds down, subtracting 1 is implied.
        A = A * A;
        n >>= 1; // Bitwise equivalent to n = n / 2
    }
    
    return res;
}

int main() {
    // Declared as long long to accept large inputs safely
    long long int A; 
    int n; 
    
    if (cin >> A >> n) {
        cout << binaryExp(A, n) << "\n";
    }
    
    return 0;
}