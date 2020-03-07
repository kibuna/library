// greatest common divisor and least common multiple
// gcd is calculated by Euclidean Algorithm
// lcm = m * n / gcd(m,n)
template <typename T = int>
T gcd(T a, T b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template <typename T = int>
T lcm(T m, T n) {
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}