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


# :heavy_check_mark: test/algebra/eratosthenes.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c499b7fa4489ae69771eea179f185e77">test/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 11:43:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/eratosthenes.cpp.html">library/algebra/eratosthenes.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/algebra/eratosthenes.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Sieve isPrime(2000000);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int l = n, r = n;
        while (!isPrime(l))
            l--;
        while (!isPrime(r))
            r++;
        cout << r - l << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/eratosthenes.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/algebra/eratosthenes.cpp"
// Eratosthenes's sieve
// create list of prime numbers in O(N)
// check if the given number is prime in O(1)
struct Sieve {
    vector<bool> isPrime;
    Sieve(size_t max) : isPrime(max + 1, true) {
        isPrime[0] = false;
        isPrime[1] = false;

        for (size_t i = 2; i * i <= max; ++i)
            if (isPrime[i])
                for (size_t j = 2; i * j <= max; ++j)
                    isPrime[i * j] = false;
    }
    bool operator()(size_t n) { return isPrime[n]; }
};
#line 8 "test/algebra/eratosthenes.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Sieve isPrime(2000000);
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int l = n, r = n;
        while (!isPrime(l))
            l--;
        while (!isPrime(r))
            r++;
        cout << r - l << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

