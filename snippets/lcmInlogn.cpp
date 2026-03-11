#include <iostream>
#include <cmath>   // We need this for the abs() function
#include <utility> // We need this for the swap() function

using namespace std;

// Using 'long long' so we can handle really huge numbers without the program crashing
long long int gcd(long long int a, long long int b) {
    
    // The GCD is always a positive number. 
    // Just in case someone types in a negative number, let's force them to be positive.
    a = abs(a);
    b = abs(b);
    
    // Keep doing this math until there is no remainder left (b hits 0)
    while (b != 0) {
        // Step 1: Find the remainder of 'a' divided by 'b' and save it in 'a'
        a %= b; 
        
        // Step 2: Swap them! 
        // Now 'a' holds our old 'b', and 'b' holds our new remainder.
        swap(a, b); 
    }
    
    // Once b finally hits 0, whatever is left in 'a' is our answer!
    return a;
}

int main() {
    // These two lines are just a standard trick to make reading and printing numbers much faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int a, b;
    
    // Wait for the user to type in two numbers. 
    // The 'if' makes sure they actually typed real numbers before we try to do math on them.
    if (cin >> a >> b) {
        
        // Calculate the GCD, print it, and drop down to a new line
        cout << gcd(a, b) << "\n"; 
    }
    
    return 0;
}