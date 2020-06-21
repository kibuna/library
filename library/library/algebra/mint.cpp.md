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


# :heavy_check_mark: library/algebra/mint.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/mint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:48:11+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/algebra/mint_pow.test.cpp.html">test/algebra/mint_pow.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/datastructure/pathmultiply_edge.test.cpp.html">test/datastructure/pathmultiply_edge.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/datastructure/vertexsetpathcomposite.test.cpp.html">test/datastructure/vertexsetpathcomposite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

