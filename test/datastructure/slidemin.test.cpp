#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/slidemin.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ret = slideMin(a, l);
    for (int i = 0; i <= n - l; ++i) {
        if (i)
            cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}