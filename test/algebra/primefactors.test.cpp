#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/primefactors.cpp"

int main() {
    lint n;
    cin >> n;
    map<lint, int> facs;
    primeFactors(n, facs);
    cout << n << ": ";
    for (auto &p : facs) {
        for (int i = 0; i < p.second; ++i) {
            cout << p.first << " ";
        }
    }
    cout << endl;
    return 0;
}
