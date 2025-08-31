#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// Vector to store first q prime numbers
vector<ll> prime;

// Function to generate prime numbers using sieve of Eratosthenes
void sieve (ll q) {
    ll limit = 1e6 + 5; // Upper bound for sieve
    vector<bool> isPrime(limit, true); // Initialize all numbers as prime

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Generate primes until we have q primes
    for(int i = 2; prime.size() < q && i <= limit; i++) {
        if (isPrime[i]) {
            prime.push_back(i); // Store prime number
            for (int j = i * i; j <= limit; j += i) isPrime[j] = false; // Mark multiples as not prime
        }
    }
}

int main() {

    ll n, q;
    cin >> n >> q; // n = number of plates, q = number of iterations

    stack<ll> stackA; // Initial stack of plates
    ll val;
    for(ll i = 0; i < n; i++) {
        cin >> val;
        stackA.push(val); // Push plates onto stack
    }

    vector<stack<ll>> stackB(q); // q stacks to hold divisible plates in each iteration
    stack<ll> temp; // Temporary stack for non-divisible plates

    sieve(q); // Generate first q primes

    // Process each iteration with prime[i]
    for (ll i = 0 ; i < q; i++) {

        while (!stackA.empty()) {
            if (stackA.top() % prime[i] == 0) stackB[i].push(stackA.top()); // Divisible by prime -> move to B[i]
            else temp.push(stackA.top()); // Non-divisible -> move to temp
            stackA.pop();
        } 

        stackA = temp; // Remaining plates become the new stackA for next iteration
        while (!temp.empty()) temp.pop(); // Clear temp stack
    }

    // Print plates from all B stacks
    for (ll i = 0; i < q; i++) {
        while (!stackB[i].empty()) {
            cout << stackB[i].top() << endl;
            stackB[i].pop();
        }
    }

    // Print remaining plates in stackA
    while (!stackA.empty()) {
        cout << stackA.top() << endl;
        stackA.pop();
    }

    return 0;
}
