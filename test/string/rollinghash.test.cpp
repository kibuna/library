#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/string/rollinghash.cpp"

int main() {
    string t, p;
    cin >> t >> p;
    int nt = t.size();
    int np = p.size();
    RollingHash th(t), ph(p);
    for (int i = 0; i <= nt - np; ++i) {
        if (th.get(i, i + np) == ph.get(0, np))
            cout << i << "\n";
    }
    return 0;
}