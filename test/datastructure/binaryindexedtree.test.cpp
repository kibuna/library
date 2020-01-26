#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/binaryindexedtree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<lint> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BinaryIndexedTree<lint> bit(a);
    vector<int> t(q), l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> l[i] >> r[i];
    }
    for (int i = 0; i < q; ++i) {
        if (t[i] == 1)
            cout << bit.query(l[i], r[i]) << endl;
        else if (t[i] == 0)
            bit.add(l[i], r[i]);
    }
    return 0;
}
