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


# :warning: library/algebra/linearequation.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/linearequation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:16:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using ld         = long double;
constexpr ld eps = 1e-10;
template <typename T>
int GaussJordan(vector<vector<T>> &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        if (is_extended && col == n - 1)
            break;

        int pivot = -1;
        T ma      = eps;
        for (int row = rank; row < m; ++row) {
            if (abs(A[row][col]) > ma) {
                ma    = abs(A[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1)
            continue;

        swap(A[pivot], A[rank]);
        auto fac = A[rank][col];
        for (int col2 = 0; col2 < n; ++col2)
            A[rank][col2] /= fac;

        for (int row = 0; row < m; ++row) {
            if (row != rank && abs(A[row][col]) > eps) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; ++col2) {
                    A[row][col2] -= A[rank][col2] * fac;
                }
            }
        }
        ++rank;
    }
    return rank;
}

template <typename T>
vector<T> linear_equation(vector<vector<T>> A, vector<T> b) {
    // extended
    int m = A.size(), n = A[0].size();
    vector<vector<T>> M(m, vector<T>(n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    vector<T> res;
    for (int row = rank; row < m; ++row)
        if (abs(M[row][n]) > eps)
            return res;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i)
        res[i] = M[i][n];
    return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/linearequation.cpp"
using ld         = long double;
constexpr ld eps = 1e-10;
template <typename T>
int GaussJordan(vector<vector<T>> &A, bool is_extended = false) {
    int m = A.size(), n = A[0].size();
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        if (is_extended && col == n - 1)
            break;

        int pivot = -1;
        T ma      = eps;
        for (int row = rank; row < m; ++row) {
            if (abs(A[row][col]) > ma) {
                ma    = abs(A[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1)
            continue;

        swap(A[pivot], A[rank]);
        auto fac = A[rank][col];
        for (int col2 = 0; col2 < n; ++col2)
            A[rank][col2] /= fac;

        for (int row = 0; row < m; ++row) {
            if (row != rank && abs(A[row][col]) > eps) {
                auto fac = A[row][col];
                for (int col2 = 0; col2 < n; ++col2) {
                    A[row][col2] -= A[rank][col2] * fac;
                }
            }
        }
        ++rank;
    }
    return rank;
}

template <typename T>
vector<T> linear_equation(vector<vector<T>> A, vector<T> b) {
    // extended
    int m = A.size(), n = A[0].size();
    vector<vector<T>> M(m, vector<T>(n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    vector<T> res;
    for (int row = rank; row < m; ++row)
        if (abs(M[row][n]) > eps)
            return res;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i)
        res[i] = M[i][n];
    return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

