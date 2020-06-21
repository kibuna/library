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


# :heavy_check_mark: test/algebra/primefactors.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c499b7fa4489ae69771eea179f185e77">test/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/primefactors.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 16:31:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/primefactors.cpp.html">library/algebra/primefactors.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/primefactors.cpp"

int main() {
    lint n;
    cin >> n;
    map<lint, int> facs;
    primeFactors(n, facs);
    cout << n << ":";
    for (auto &p : facs) {
        for (int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/primefactors.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/algebra/primefactors.cpp"
// list up all prime factors, including how many times does it have the prime
template <typename T = int>
void primeFactors(T a, map<T, int> &facs) {
    double sqrtA = sqrt(a);
    for (int i = 2; i <= sqrtA + 1e-10; ++i) {
        while (a % i == 0) {
            facs[i]++;
            a /= i;
        }
    }
    if (a > sqrtA)
        facs[a]++;
    return;
}
#line 8 "test/algebra/primefactors.test.cpp"

int main() {
    lint n;
    cin >> n;
    map<lint, int> facs;
    primeFactors(n, facs);
    cout << n << ":";
    for (auto &p : facs) {
        for (int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

