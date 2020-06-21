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


# :warning: library/algebra/mintarb.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/mintarb.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:49:22+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct modint {
    lint v;
    static lint &mod() {
        static lint mod = 0;
        return mod;
    }
    static lint set_mod(lint md) { mod() = md; }
    modint() : v(0) {}
    modint(signed v) : v(v) {}
    modint(lint t) {
        assert(mod() != 0);
        v = t % mod();
        if (v < 0)
            v += mod();
    }

    modint pow(lint k) {
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
    modint inv() { return pow(mod() - 2); }

    modint &operator+=(modint a) {
        v += a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator-=(modint a) {
        v += mod() - a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator*=(modint a) {
        v = v * a.v % mod();
        return *this;
    }
    modint &operator/=(modint a) { return (*this) *= a.inv(); }

    modint operator+(modint a) const { return modint(v) += a; };
    modint operator-(modint a) const { return modint(v) -= a; };
    modint operator*(modint a) const { return modint(v) *= a; };
    modint operator/(modint a) const { return modint(v) /= a; };

    modint operator-() const { return v ? modint(mod - v) : modint(v); }

    bool operator==(const modint a) const { return v == a.v; }
    bool operator!=(const modint a) const { return v != a.v; }
    bool operator<(const modint a) const { return v < a.v; }
};
using mint = modint;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }
// DO CALL mint::set_mod()
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/mintarb.cpp"
struct modint {
    lint v;
    static lint &mod() {
        static lint mod = 0;
        return mod;
    }
    static lint set_mod(lint md) { mod() = md; }
    modint() : v(0) {}
    modint(signed v) : v(v) {}
    modint(lint t) {
        assert(mod() != 0);
        v = t % mod();
        if (v < 0)
            v += mod();
    }

    modint pow(lint k) {
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
    modint inv() { return pow(mod() - 2); }

    modint &operator+=(modint a) {
        v += a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator-=(modint a) {
        v += mod() - a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator*=(modint a) {
        v = v * a.v % mod();
        return *this;
    }
    modint &operator/=(modint a) { return (*this) *= a.inv(); }

    modint operator+(modint a) const { return modint(v) += a; };
    modint operator-(modint a) const { return modint(v) -= a; };
    modint operator*(modint a) const { return modint(v) *= a; };
    modint operator/(modint a) const { return modint(v) /= a; };

    modint operator-() const { return v ? modint(mod - v) : modint(v); }

    bool operator==(const modint a) const { return v == a.v; }
    bool operator!=(const modint a) const { return v != a.v; }
    bool operator<(const modint a) const { return v < a.v; }
};
using mint = modint;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }
// DO CALL mint::set_mod()

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

