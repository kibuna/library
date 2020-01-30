#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/factors.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    auto facs = factors(c);
    int ret   = 0;
    for (auto &f : facs) {
        if (a <= f && f <= b)
            ret++;
    }
    cout << ret << "\n";
    return 0;
}