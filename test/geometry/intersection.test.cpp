#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<Segment> f, t;
    for (int i = 0; i < q; ++i) {
        Point a, b, c, d;
        cin >> a >> b >> c >> d;
        f.emplace_back(a, b);
        t.emplace_back(c, d);
    }
    for (int i = 0; i < q; ++i) {
        if (intersect(f[i], t[i]))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}