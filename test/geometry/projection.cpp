#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Line base(p1, p2);
    int q;
    cin >> q;
    vector<Point> r(q);
    for (int i = 0; i < q; ++i) {
        cin >> r[i].x >> r[i].y;
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < q; ++i) {
        Point ret = projection(base, r[i]);
        cout << ret.x << " " << ret.y << "\n";
    }
}