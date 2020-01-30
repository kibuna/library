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


# :heavy_check_mark: test/algebra/factors.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/factors.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-30 20:35:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/factors.cpp.html">library/algebra/factors.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/factors.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    auto facs = factors(c);
    int ret   = 0;
    for (auto &f : facs) {
        if (a <= f && f <= b)
            ret++;
    }
    cout << ret << "\n";
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/factors.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/algebra/../../library/algebra/factors.cpp"
// list up all factors
template <typename T>
set<T> factors(T a) {
    set<T> facs;
    for (T i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            facs.insert(i);
            facs.insert(a / i);
        }
    }
    return facs;
}
#line 8 "test/algebra/factors.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    auto facs = factors(c);
    int ret   = 0;
    for (auto &f : facs) {
        if (a <= f && f <= b)
            ret++;
    }
    cout << ret << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

