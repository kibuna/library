struct Combination {
    vector<lint> fac, finv, inv;
    Combination(lint maxN) : fac(maxN + 100), finv(maxN + 100), inv(maxN + 100) {
        maxN += 100; // for safety
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (lint i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % mod;
            inv[i]  = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint operator()(lint n, lint k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};