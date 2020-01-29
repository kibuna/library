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


# :heavy_check_mark: test/algebra/gcd.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/gcd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 00:09:13+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/gcd.cpp.html">library/algebra/gcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/gcd.cpp"

int main() {
    lint n;
    cin >> n;
    vector<lint> a(n);
    lint ret = 1;
    for (int i = 0; i < n; ++i) {
        lint a;
        cin >> a;
        ret = lcm(ret, a);
    }
    cout << ret << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/gcd.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/algebra/../../library/algebra/gcd.cpp"
// greatest common divisor and least common multiple
// gcd is calculated by Euclidean Algorithm
// lcm = m * n / gcd(m,n)
template <typename T = int>
T gcd(T a, T b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template <typename T = int>
T lcm(T m, T n) {
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}#line 8 "test/algebra/gcd.test.cpp"

int main() {
    lint n;
    cin >> n;
    vector<lint> a(n);
    lint ret = 1;
    for (int i = 0; i < n; ++i) {
        lint a;
        cin >> a;
        ret = lcm(ret, a);
    }
    cout << ret << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

