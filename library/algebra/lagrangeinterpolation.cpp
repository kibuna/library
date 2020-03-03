// O(n^2)
// https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93

template <typename T>
vector<T> lagrange_interpolation(vector<T> x, vector<T> y) {
    const int n = x.size();
    for (int i = 0; i < n; ++i) {
        T t = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j)
                t *= x[i] - x[j];
        }
        y[i] /= t;
    }
    ll cur = 0, nxt = 1;
    vector<vector<T>> dp(2, vector<T>(n + 1));
    dp[0][0] = -x[0], dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            dp[nxt][j] = dp[cur][j] * -1 * x[i];
            if (j >= 1)
                dp[nxt][j] += dp[cur][j - 1];
        }
        swap(nxt, cur);
    }
    vector<T> xinv(n);
    for (int i = 0; i < n; ++i)
        xinv[i] = T(1) / x[i];
    vector<T> ret(n, 0); // f(x)
    for (int i = 0; i < n; ++i) {
        if (y[i] == 0)
            continue;
        if (x[i] == 0) {
            for (int j = 0; j < n; ++j) {
                ret[j] += dp[cur][j + 1] * y[i];
            }
        } else {
            ret[0] -= dp[cur][0] * xinv[i] * y[i];
            T pre = -dp[cur][0] * xinv[i];
            for (int j = 1; j < n; ++j) {
                ret[j] -= (dp[cur][j] - pre) * xinv[i] * y[i];
                pre = -(dp[cur][j] - pre) * xinv[i];
            }
        }
    }
    return ret;
}
