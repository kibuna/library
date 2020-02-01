#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/eratosthenes.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Sieve isPrime(2000000);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int l = n, r = n;
        while (!isPrime(l))
            l--;
        while (!isPrime(r))
            r++;
        cout << r - l << "\n";
    }
    return 0;
}