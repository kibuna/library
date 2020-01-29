#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = (1LL << 31) - 1;

#include "../../library/datastructure/segmenttreelazy.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return min(l, r); };
    lint unit = inf;
    SegmentTreeLazy<lint> sg(n, f, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.update(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << sg.query(s, t + 1) << "\n";
        }
    }
    return 0;
}