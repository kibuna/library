#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#define ERROR 1e-6

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Point> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    auto ret = convex_hull(x);
    cout << ret.size() << "\n";
    int idx = 0;
    for (int i = 1; i < (int)ret.size(); ++i) {
        if (ret[idx].y > ret[i].y || (eq(ret[idx].y, ret[i].y) && ret[idx].x > ret[idx].x))
            idx = i;
    }
    for (int i = 0; i < (int)ret.size(); ++i) {
        cout << ret[(idx + i) % int(ret.size())] << "\n";
    }
    return 0;
}