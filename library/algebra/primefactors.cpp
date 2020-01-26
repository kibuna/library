// list up all prime factors, including how many times does it have the prime
template <typename T = int>
void primeFactors(T a, map<T, int> &facs) {
    double sqrtA = sqrt(a);
    for (int i = 2; i <= sqrtA + 1e-10; ++i) {
        while (a % i == 0) {
            facs[i]++;
            a /= i;
        }
    }
    if (a > sqrtA)
        facs[a]++;
    return;
}