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
    - Last commit date: 2020-01-27 00:09:13+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/algebra/mint_pow.test.cpp.html">test/algebra/mint_pow.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/datastructure/pathmultiply_edge.test.cpp.html">test/datastructure/pathmultiply_edge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct mint {
    lint v;
    lint _mod;
    mint() : v(0) {}
    mint(signed v, lint _mod = mod) : v(v), _mod(_mod) {}
    mint(lint t, lint _mod = mod) : _mod(_mod) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    mint pow(lint k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }
    mint inv() { return pow(_mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(_mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};
ostream &operator<<(ostream &os, mint m) { return os << m.v; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/mint.cpp"
struct mint {
    lint v;
    lint _mod;
    mint() : v(0) {}
    mint(signed v, lint _mod = mod) : v(v), _mod(_mod) {}
    mint(lint t, lint _mod = mod) : _mod(_mod) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    mint pow(lint k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }
    mint inv() { return pow(_mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(_mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};
ostream &operator<<(ostream &os, mint m) { return os << m.v; }

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

