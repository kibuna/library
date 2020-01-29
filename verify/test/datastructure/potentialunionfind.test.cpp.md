---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/datastructure/potentialunionfind.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/potentialunionfind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 20:59:58+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/unionfindpotential.cpp.html">library/datastructure/unionfindpotential.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/potentialunionfind.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/datastructure/../../library/datastructure/unionfindpotential.cpp"
template <class Abel>
struct UnionFindPotential {
    vector<int> parent, rank;
    vector<Abel> diff_weight;

    UnionFindPotential(int n = 1, Abel SUM_UNITY = 0)
        : parent(n + 1), rank(n + 1, 0), diff_weight(n + 1, SUM_UNITY) {
        iota(parent.begin(), parent.end(), 0);
    }
    int root(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            int r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        parent[y] = x;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
};
#line 9 "test/datastructure/potentialunionfind.test.cpp"

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
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

