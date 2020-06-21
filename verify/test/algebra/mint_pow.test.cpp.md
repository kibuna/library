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


# :heavy_check_mark: test/algebra/mint_pow.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c499b7fa4489ae69771eea179f185e77">test/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/algebra/mint_pow.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:48:11+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/mint.cpp.html">library/algebra/mint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 1000000007;

#include "../../library/algebra/mint.cpp"

int main() {
    lint m, n;
    cin >> m >> n;
    cout << mint(m).pow(n) << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/algebra/mint_pow.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 1000000007;

#line 1 "library/algebra/mint.cpp"
template <lint mod>
struct modint {
    lint v;
    constexpr modint(lint t = 0) noexcept {
        v = t % mod;
        if (v < 0)
            v += mod;
    }
    constexpr modint pow(lint k) noexcept {
        modint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static modint add_identity() { return modint(0); }
    static modint mul_identity() { return modint(1); }
    constexpr modint inv() { return pow(mod - 2); }

    constexpr modint &operator+=(const modint a) noexcept {
        v += a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint a) noexcept {
        v += mod - a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator*=(const modint a) noexcept {
        v = v * a.v % mod;
        return *this;
    }
    constexpr modint &operator/=(const modint a) noexcept { return (*this) *= a.inv(); }

    constexpr modint operator+(const modint a) const noexcept { return modint(v) += a; };
    constexpr modint operator-(const modint a) const noexcept { return modint(v) -= a; };
    constexpr modint operator*(const modint a) const noexcept { return modint(v) *= a; };
    constexpr modint operator/(const modint a) const noexcept { return modint(v) /= a; };
    constexpr modint operator-() const noexcept { return v ? modint(mod - v) : modint(v); }

    constexpr bool operator==(const modint a) const noexcept { return v == a.v; }
    constexpr bool operator!=(const modint a) const noexcept { return v != a.v; }
    constexpr bool operator<(const modint a) const noexcept { return v < a.v; }
};
using mint = modint<mod>;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }
#line 9 "test/algebra/mint_pow.test.cpp"

int main() {
    lint m, n;
    cin >> m >> n;
    cout << mint(m).pow(n) << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

