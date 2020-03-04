#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Circle c1, c2;
    cin >> c1.p.x >> c1.p.y >> c1.r;
    cin >> c2.p.x >> c2.p.y >> c2.r;
    cout << intersect(c1, c2) << "\n";
    return 0;
}