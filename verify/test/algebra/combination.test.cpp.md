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


# :heavy_check_mark: test/algebra/combination.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c499b7fa4489ae69771eea179f185e77">test/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/combination.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-30 22:27:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/combination.cpp.html">library/algebra/combination.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 100000007;

#include "../../library/algebra/combination.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1)
        swap(a1, b1);
    if (a2 > b2)
        swap(a2, b2);
    int mult = 1;
    int h1   = b1 - a1;
    int w1   = b2 - a2;
    int h2   = a1 - b1 + r;
    int w2   = a2 - b2 + c;
    if (h1 == h2)
        mult *= 2;
    if (w1 == w2)
        mult *= 2;
    int h = min(h1, h2);
    int w = min(w1, w2);
    Combination nCk(2000);
    cout << (nCk(h + w, w) * mult) % mod << "\n";
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/combination.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 100000007;

#line 1 "library/algebra/combination.cpp"
struct Combination {
    vector<lint> fac, finv, inv;
    Combination(lint maxN) : fac(maxN + 100), finv(maxN + 100), inv(maxN + 100) {
        maxN += 100; // for safety
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (lint i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % mod;
            inv[i]  = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint operator()(lint n, lint k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};
#line 9 "test/algebra/combination.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1)
        swap(a1, b1);
    if (a2 > b2)
        swap(a2, b2);
    int mult = 1;
    int h1   = b1 - a1;
    int w1   = b2 - a2;
    int h2   = a1 - b1 + r;
    int w2   = a2 - b2 + c;
    if (h1 == h2)
        mult *= 2;
    if (w1 == w2)
        mult *= 2;
    int h = min(h1, h2);
    int w = min(w1, w2);
    Combination nCk(2000);
    cout << (nCk(h + w, w) * mult) % mod << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

