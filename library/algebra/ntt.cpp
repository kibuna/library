int extgcd(int a, int b, int &x, int &y) {
    int g = a;
    x     = 1;
    y     = 0;
    if (b != 0)
        g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

template <int mod = 998244353>
int modinv(int a) {
    int x, y;
    if (extgcd(a, mod, x, y) != 1)
        return 0;
    return (mod + x % mod) % mod;
}

template <int mod = 998244353>
int modpow(int x, int k) {
    int ret = 1;
    for (x %= mod; k > 0; x = 1LL * x * x % mod, k >>= 1)
        if (k & 1)
            ret = 1LL * ret * x % mod;
    return ret;
}

template <int mod = 998244353, bool inverse = false>
vector<int> ntt(vector<int> a) {
    int e = 0, n = a.size();
    assert((n & (n - 1)) == 0);
    while (n != (1 << e))
        e++;
    for (int j = 0; j < n; ++j) {
        int m2 = 0;
        for (int k = 0; k < e; ++k) {
            if (j & (1 << k))
                m2 |= (1 << (e - 1 - k));
        }
        if (j < m2)
            swap(a[j], a[m2]);
    }
    for (int t = 1; t < n; t *= 2) {
        int r = modpow<mod>(3, (mod - 1) / (t * 2));
        if (inverse)
            r = modinv<mod>(r);
        for (int i = 0; i < n; i += 2 * t) {
            int power = 1;
            for (int j = 0; j < t; ++j) {
                int x = a[i + j], y = 1LL * a[i + t + j] * power % mod;
                a[i + j]     = (x + y) % mod;
                a[i + t + j] = (x - y + mod) % mod;
                power        = 1LL * power * r % mod;
            }
        }
    }
    if (inverse) {
        for (int i = 0, ni = modinv<mod>(n); i < n; ++i) {
            a[i] = 1LL * a[i] * ni % mod;
        }
    }
    return a;
}

template <int mod = 998244353>
vector<int> conv_multiply(vector<int> a, vector<int> b) {
    int size = 1;
    int n    = a.size() + b.size() - 1;
    while (size < n)
        size <<= 1;
    a.resize(size, 0);
    b.resize(size, 0);
    a = ntt<mod>(a);
    b = ntt<mod>(b);
    for (int i = 0; i < size; ++i) {
        a[i] = 1LL * a[i] * b[i] % mod;
    }
    auto c = ntt<mod, true>(a);
    c.resize(n);
    return c;
}
