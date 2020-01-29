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


# :warning: library/algebra/squarematrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/squarematrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 22:23:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <size_t N, typename R>
struct SquareMatrix {
    using arr = array<R, N>;
    using mat = array<arr, N>;
    mat dat;

    SquareMatrix() {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                dat[i][j] = R::add_identity();
    }
    SquareMatrix &operator=(const SquareMatrix &a) {
        dat = a.dat;
        return (*this);
    }
    bool operator==(const SquareMatrix &a) const { return dat == a.dat; }

    size_t size() const { return N; };
    arr &operator[](size_t k) { return dat[k]; };
    const arr &operator[](size_t k) const { return dat[k]; };

    static SquareMatrix add_identity() { return SquareMatrix(); }
    static SquareMatrix mul_identity() {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            res[i][i] = R::mul_identity();
        return res;
    }

    SquareMatrix operator*(const SquareMatrix &B) const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                for (size_t k = 0; k < N; k++)
                    res[i][j] = res[i][j] + (dat[i][k] * B[k][j]);
        return res;
    }

    SquareMatrix operator+(const SquareMatrix &B) const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                res[i][j] = dat[i][j] + B[i][j];
        return res;
    }

    SquareMatrix pow(long long n) const {
        SquareMatrix a = *this, res = mul_identity();
        while (n) {
            if (n & 1)
                res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/squarematrix.cpp"
template <size_t N, typename R>
struct SquareMatrix {
    using arr = array<R, N>;
    using mat = array<arr, N>;
    mat dat;

    SquareMatrix() {
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                dat[i][j] = R::add_identity();
    }
    SquareMatrix &operator=(const SquareMatrix &a) {
        dat = a.dat;
        return (*this);
    }
    bool operator==(const SquareMatrix &a) const { return dat == a.dat; }

    size_t size() const { return N; };
    arr &operator[](size_t k) { return dat[k]; };
    const arr &operator[](size_t k) const { return dat[k]; };

    static SquareMatrix add_identity() { return SquareMatrix(); }
    static SquareMatrix mul_identity() {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            res[i][i] = R::mul_identity();
        return res;
    }

    SquareMatrix operator*(const SquareMatrix &B) const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                for (size_t k = 0; k < N; k++)
                    res[i][j] = res[i][j] + (dat[i][k] * B[k][j]);
        return res;
    }

    SquareMatrix operator+(const SquareMatrix &B) const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                res[i][j] = dat[i][j] + B[i][j];
        return res;
    }

    SquareMatrix pow(long long n) const {
        SquareMatrix a = *this, res = mul_identity();
        while (n) {
            if (n & 1)
                res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

