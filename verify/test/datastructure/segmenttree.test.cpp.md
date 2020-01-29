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


# :heavy_check_mark: test/datastructure/segmenttree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/segmenttree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 00:06:22+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/segmenttree.cpp.html">library/datastructure/segmenttree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
using pii      = pair<lint, lint>;
const lint mod = 998244353;

#include "../../library/datastructure/segmenttree.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    auto f = [](pii l, pii r) {
        lint a = r.first * l.first % mod;
        lint b = (r.first * l.second % mod + r.second) % mod;
        return make_pair(a, b);
    };
    const pii unit = {1, 0};
    SegmentTree<pii> sg(a, f, unit);
    for (int i = 0; i < q; ++i) {
        lint t;
        cin >> t;
        if (t == 1) {
            lint l, r, x;
            cin >> l >> r >> x;
            auto p = sg.query(l, r);
            cout << (p.first * x % mod + p.second) % mod << "\n";
        } else {
            lint p, c, d;
            cin >> p >> c >> d;
            sg.update(p, {c, d});
        }
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/segmenttree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
using pii      = pair<lint, lint>;
const lint mod = 998244353;

#line 1 "test/datastructure/../../library/datastructure/segmenttree.cpp"
// 0-indexed bottom up Segment Tree
// UNIT is the identity element of operation func
template <typename T = int>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> dat;
    F func;
    T UNIT;

    SegmentTree(int n_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        // full binary tree: num of leaves = n = 2^k >= n_
        while (n < n_)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
    }
    SegmentTree(vector<T> v_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n      = 1;
        int nv = v_.size();
        while (n < nv)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
        for (int i = 0; i < nv; ++i) {
            dat[n - 1 + i] = v_[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        // leaves are at index n-1 to 2*n-2
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            // k -> parent node
            k = (k - 1) / 2;
            // func(child nodes)
            dat[k] = func(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // get result of func() in [l, r)
    T query(int l, int r) {
        l += n - 1;
        r += n - 1;
        T retl = UNIT, retr = UNIT;
        while (l < r) {
            if ((l & 1) == 0)
                retl = func(retl, dat[l]);
            if ((r & 1) == 0)
                retr = func(dat[r - 1], retr);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return func(retl, retr);
    }
};
#line 11 "test/datastructure/segmenttree.test.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    auto f = [](pii l, pii r) {
        lint a = r.first * l.first % mod;
        lint b = (r.first * l.second % mod + r.second) % mod;
        return make_pair(a, b);
    };
    const pii unit = {1, 0};
    SegmentTree<pii> sg(a, f, unit);
    for (int i = 0; i < q; ++i) {
        lint t;
        cin >> t;
        if (t == 1) {
            lint l, r, x;
            cin >> l >> r >> x;
            auto p = sg.query(l, r);
            cout << (p.first * x % mod + p.second) % mod << "\n";
        } else {
            lint p, c, d;
            cin >> p >> c >> d;
            sg.update(p, {c, d});
        }
    }
    return 0;
}
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

