// Eratosthenes's sieve
// create list of prime numbers in O(N)
// check if the given number is prime in O(1)
struct Sieve {
    vector<bool> isPrime;
    Sieve(size_t max) : isPrime(max + 1, true) {
        isPrime[0] = false;
        isPrime[1] = false;

        for (size_t i = 2; i * i <= max; ++i)
            if (isPrime[i])
                for (size_t j = 2; i * j <= max; ++j)
                    isPrime[i * j] = false;
    }
    bool operator()(size_t n) { return isPrime[n]; }
};