#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/segmenttreelazyadd.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return l + r; };
    auto g    = [](lint l, lint r) { return l + r; };
    lint unit = 0;
    SegmentTreeLazyAdd<lint> sg(n + 1, f, g, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.add(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << sg.query(s, t + 1) << "\n";
        }
    }
    return 0;
}