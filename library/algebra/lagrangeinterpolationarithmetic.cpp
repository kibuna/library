// fast polynomial interpolation for arithmetic sequence O(n log mod)
// x_i = a + i*d : y_i, 0<=i<=n
template <typename T>
T LagrangeInterpolationArithmetic(T a, T d, vector<T> y, T x) {
    const lint n = y.size() - 1;
    T ret = 0, ft = 1;
    for (int i = 0; i < n + 1; ++i) {
        ft *= x - (a + d * i);
    }
    T f = 1;
    for (int i = 1; i < n + 1; ++i) {
        f *= -d * i;
    }
    ret += y[0] / f * ft / (x - a);
    for (int i = 0; i < n; ++i) {
        f *= d * (i + 1) / (d * (i - n));
        ret += y[i + 1] / f * ft / (x - a - d * (i + 1));
    }
    return ret;
}
