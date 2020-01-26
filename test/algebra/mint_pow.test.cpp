#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 1000000007;

#include "../../library/algebra/mint.cpp"

int main() {
    lint m, n;
    cin >> m >> n;
    cout << mint(m).pow(n) << "\n";
    return 0;
}
