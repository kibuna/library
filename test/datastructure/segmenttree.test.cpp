#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/segmenttree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto f          = [](lint l, lint r) { return min(l, r); };
    const lint unit = 1LL << 60;
    SegmentTree<lint> sg(a, f, unit);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << sg.query(l, r) << "\n";
    }
    return 0;
}