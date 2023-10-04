#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime using the Sieve of Eratosthenes algorithm
int sieve(int n) {  // O(nloglogn)
    vector<bool> is_prime(n + 1, true); 
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) 
                is_prime[j] = false;
        }
    }
    return is_prime[n]; // Returns true if n is prime, false otherwise
}

int main() {
    int n;
    cout << "Enter a number. I will tell if it is prime or not." << endl;
    cin >> n;

    // Check if the input number is prime using the sieve function
    if (sieve(n)) {
        cout << n << " is prime\n"; // Output if the number is prime
    } else {
        cout << n << " is not prime\n"; // Output if the number is not prime
    }
}
