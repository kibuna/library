#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/unionfindpotential.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    UnionFindPotential<lint> uf(n);
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            uf.unite(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            if (uf.isSame(x, y))
                cout << uf.diff(x, y) << "\n";
            else
                cout << "?"
                     << "\n";
        }
    }
    return 0;
}