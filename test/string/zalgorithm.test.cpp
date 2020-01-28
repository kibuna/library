#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/string/zalgorithm.cpp"

int main() {
    string s;
    cin >> s;
    auto ret = ZAlgorithm(s);
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i)
            cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}