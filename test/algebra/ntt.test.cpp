#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;
using lint        = long long;
constexpr int mod = 998244353;

#include "../../library/algebra/ntt.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    auto c = conv_multiply<mod>(a, b);
    for (int i = 0; i < (int)c.size(); ++i) {
        if (i)
            cout << " ";
        cout << c[i];
    }
    cout << endl;
    return 0;
}