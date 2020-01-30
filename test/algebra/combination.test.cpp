#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 100000007;

#include "../../library/algebra/combination.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1)
        swap(a1, b1);
    if (a2 > b2)
        swap(a2, b2);
    int mult = 1;
    int h1   = b1 - a1;
    int w1   = b2 - a2;
    int h2   = a1 - b1 + r;
    int w2   = a2 - b2 + c;
    if (h1 == h2)
        mult *= 2;
    if (w1 == w2)
        mult *= 2;
    int h = min(h1, h2);
    int w = min(w1, w2);
    Combination nCk(2000);
    cout << (nCk(h + w, w) * mult) % mod << "\n";
    return 0;
}