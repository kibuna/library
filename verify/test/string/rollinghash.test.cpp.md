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


# :heavy_check_mark: test/string/rollinghash.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/string/rollinghash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 21:32:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/string/rollinghash.cpp.html">library/string/rollinghash.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/string/rollinghash.cpp"

int main() {
    string t, p;
    cin >> t >> p;
    int nt = t.size();
    int np = p.size();
    RollingHash th(t), ph(p);
    for (int i = 0; i <= nt - np; ++i) {
        if (th.get(i, i + np) == ph.get(0, np))
            cout << i << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/string/rollinghash.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/string/../../library/string/rollinghash.cpp"
// original: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class RollingHash {
  private:
    using ulint                        = unsigned long long;
    static constexpr ulint mask30      = (1ULL << 30) - 1;
    static constexpr ulint mask31      = (1ULL << 31) - 1;
    static constexpr ulint mod         = (1ULL << 61) - 1;
    static constexpr ulint positivizer = mod * ((1ULL << 3) - 1);
    static constexpr unsigned int base = 1033;
    int len;
    std::vector<ulint> pow_b, hash;
    static ulint mul(ulint l, ulint r) {
        const ulint lu        = l >> 31;
        const ulint ld        = l & mask31;
        const ulint ru        = r >> 31;
        const ulint rd        = r & mask31;
        const ulint middleBit = ld * ru + lu * rd;
        return ((lu * ru) << 1) + ld * rd + ((middleBit & mask30) << 31) + (middleBit >> 30);
    }
    static ulint calcMod(ulint val) {
        val = (val & mod) + (val >> 61);
        if (val > mod)
            val -= mod;
        return val;
    }

  public:
    template <typename T>
    RollingHash(const T &s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
        pow_b[0] = 1;
        hash[0]  = 1;
        for (int i = 0; i < len; ++i) {
            pow_b[i + 1] = calcMod(mul(pow_b[i], base));
            hash[i + 1]  = calcMod(mul(hash[i], base) + s[i]);
        }
    }
    // hash for [l, r)
    ulint get(int l, int r) const { return calcMod(hash[r] + positivizer - mul(hash[l], pow_b[r - l])); }
    // length of longest common prefix
    int lcp(const RollingHash &rhs, int l1, int r1, int l2, int r2) const {
        int lb = 0, ub = std::min(r1 - l1, r2 - l2) + 1;
        while (ub - lb > 1) {
            const int md                                         = (lb + ub) >> 1;
            (get(l1, l1 + md) == rhs.get(l2, l2 + md) ? lb : ub) = md;
        }
        return lb;
    }
};
#line 8 "test/string/rollinghash.test.cpp"

int main() {
    string t, p;
    cin >> t >> p;
    int nt = t.size();
    int np = p.size();
    RollingHash th(t), ph(p);
    for (int i = 0; i <= nt - np; ++i) {
        if (th.get(i, i + np) == ph.get(0, np))
            cout << i << "\n";
    }
    return 0;
}
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

