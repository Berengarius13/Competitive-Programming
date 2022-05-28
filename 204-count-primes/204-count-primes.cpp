/***
* Sieve or eratosthenes
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool> isPrime(n, 1); // Assume every every number is prime initially
        isPrime[0] = isPrime[1] = 0; // Obvisously 1 and 2 are not prime
        for(int i = 2; i < sqrt(n); i++){
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