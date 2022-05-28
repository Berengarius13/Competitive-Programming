/***
* Sieve or eratosthenes
* Time complexity
* If just for divisors loop will run like this:-
    n/2 + n/3 + n/4 + n/5 ... 1 (If we take all divisors)
    = n(log(n))
    here we are doing just for primes so:-
    n/2 + n/3 + n/5 + n/7 
    = n(log(log(n))) Will be time complexity
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool> isPrime(n, 1); // Assume every every number is prime initially
        isPrime[0] = isPrime[1] = 0; // Obvisously 1 and 2 are not prime
        for(int i = 2; i < sqrt(n); i++){
            if(isPrime[i] == 1)               // Check only for prime numbers
                for(int j = (i+i); j < n; j = j+i)// Basically i ka table, 2i, 3i, 4i, 5i
                isPrime[j] = 0;
        }
        int count = 0;
        for(auto it : isPrime)
            if(it == 1)
                count++;
        return count;
    }
};