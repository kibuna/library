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


# :heavy_check_mark: test/datastructure/binaryindexedtree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd2863e470d2af8ee92181d6e8c27bbc">test/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/binaryindexedtree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-26 16:04:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/binaryindexedtree.cpp.html">library/datastructure/binaryindexedtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/binaryindexedtree.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<lint> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BinaryIndexedTree<lint> bit(a);
    vector<int> t(q), l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> l[i] >> r[i];
    }
    for (int i = 0; i < q; ++i) {
        if (t[i] == 1)
            cout << bit.query(l[i], r[i]) << endl;
        else if (t[i] == 0)
            bit.add(l[i], r[i]);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/binaryindexedtree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/datastructure/binaryindexedtree.cpp"
// Binary Indexed Tree / Fenwick tree
// calculate partial sum in O(logN)
// update single datum in O(logN)
// lower_bound is binary search O(logN)
// 0-indexed!!!
template <typename T = int>
struct BinaryIndexedTree {
    int n;
    vector<T> bit;
    BinaryIndexedTree(int n_) : n(n_), bit(n_ + 1, 0) {}
    BinaryIndexedTree(vector<T> const &init) : n(init.size()), bit(init.size() + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            bit[i] = init[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            if (i + (i & -i) <= n)
                bit[i + (i & -i)] += bit[i];
        }
    }
    T sum(int i) {
        i++;
        T s = 0;
        for (int x = i; x > 0; x -= (x & -x))
            s += bit[x];
        return s;
    }
    void add(int i, T a) {
        i++;
        if (i == 0)
            return;
        for (int x = i; x <= n; x += (x & -x))
            bit[x] += a;
    }
    int lower_bound(int w) {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    int upper_bound(int w) {
        if (w < 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] <= w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
};
#line 8 "test/datastructure/binaryindexedtree.test.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<lint> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BinaryIndexedTree<lint> bit(a);
    vector<int> t(q), l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> l[i] >> r[i];
    }
    for (int i = 0; i < q; ++i) {
        if (t[i] == 1)
            cout << bit.query(l[i], r[i]) << endl;
        else if (t[i] == 0)
            bit.add(l[i], r[i]);
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

