// calculates nCk / 2^n
// https://www.slideshare.net/chokudai/abc011
// editorial D
struct CombinationProb {
    vector<vector<long double>> fac;
    CombinationProb(int maxN) {
        fac.resize(maxN + 2, vector<long double>(maxN + 2, 0.0));
        fac[0][0] = 1.0;
        for (int i = 1; i <= maxN; ++i) {
            fac[i][0] = fac[i - 1][0] / 2.0;
            for (int j = 1; j <= i + 1; ++j) {
                fac[i][j] = (fac[i - 1][j] + fac[i - 1][j - 1]) / 2.0;
            }
        }
    }
    long double operator()(int n, int k) { return fac[n][k]; }
};