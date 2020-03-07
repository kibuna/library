#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

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
    sort(x.begin(), x.end(), sort_t);
    for (int i = 0; i < n; ++i) {
        cout << int(x[i].x) << " " << int(x[i].y) << "\n";
    }
    return 0;
}