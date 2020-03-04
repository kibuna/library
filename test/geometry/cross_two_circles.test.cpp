#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 1e-6

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Point p1, p2;
    double r1, r2;
    cin >> p1 >> r1;
    cin >> p2 >> r2;
    Circle c1(p1, r1), c2(p2, r2);
    auto ret = crosspoint(c1, c2);
    if (!sort_x(ret.first, ret.second))
        swap(ret.first, ret.second);
    cout << fixed << setprecision(8) << ret.first << " " << ret.second << endl;
    return 0;
}