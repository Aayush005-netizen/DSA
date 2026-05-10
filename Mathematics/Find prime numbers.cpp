/*Problem statement
You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.

Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.

You can assume that the value of N will always be greater than 1. So, the answer will always exist.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
2 <= N <= 10^7

Where ‘N’ is the given positive integer.

Time Limit: 1sec
Sample Input 1 :
7
Sample Output 1 :
2 3 5 7
Sample Output 1 Explanation:
For the given input, all prime numbers from 2 to 7 are 2, 3, 5 and 7.
Sample Input 2 :
30
Sample Output 2 :
2 3 5 7 11 13 17 19 23 29*/




vector<int> primeNumbersTillN(int N) {
    vector<bool> sieve(N + 1, true); // assume all are prime
    sieve[0] = sieve[1] = false;     // 0 and 1 are not prime

    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            // mark all multiples of i as not prime
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<int> v;
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) v.emplace_back(i);
    }
    return v;
}


/*
How it works

Start with all numbers marked as prime
For each prime i, mark all its multiples as not prime
Start marking from i*i because smaller multiples were already marked by previous primes
Finally, collect all indices that are still marked as prime and return them
*/