#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/mygcd.cpp"

int main() {
    lint n;
    cin >> n;
    vector<lint> a(n);
    lint ret = 1;
    for (int i = 0; i < n; ++i) {
        lint a;
        cin >> a;
        ret = lcm(ret, a);
    }
    cout << ret << "\n";
    return 0;
}
