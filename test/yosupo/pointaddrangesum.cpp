#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/binaryindexedtree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BinaryIndexedTree bit(a);
    for (int i = 0; i < q; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t)
            cout << bit.query(l, r) << "\n";
        else
            bit.add(l, r);
    }
    return 0;
}