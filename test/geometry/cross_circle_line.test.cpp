#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 1e-6

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Circle c;
    cin >> c.p.x >> c.p.y >> c.r;
    int q;
    cin >> q;
    vector<Line> ls;
    for (int i = 0; i < q; ++i) {
        Point a, b;
        cin >> a >> b;
        ls.emplace_back(a, b);
    }
    for (int i = 0; i < q; ++i) {
        auto ret = crosspoint(c, ls[i]);
        if (!sort_x(ret.first, ret.second))
            swap(ret.first, ret.second);
        cout << fixed << setprecision(8) << ret.first << " " << ret.second << "\n";
    }
    return 0;
}