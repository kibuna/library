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


# :heavy_check_mark: test/geometry/reflection.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6f6f0638f7867790eb83eef8fd5b53f2">test/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometry/reflection.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-07 15:17:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/geometry/geometry.cpp.html">library/geometry/geometry.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 1e-8

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/geometry/geometry.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Line base(p1, p2);
    int q;
    cin >> q;
    vector<Point> r(q);
    for (int i = 0; i < q; ++i) {
        cin >> r[i].x >> r[i].y;
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < q; ++i) {
        Point ret = reflect(base, r[i]);
        cout << ret.x << " " << ret.y << "\n";
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometry/reflection.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 1e-8

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/geometry/geometry.cpp"
using Real     = long double;
const Real eps = 1e-10;
inline bool eq(Real a, Real b) { return fabs(a - b) < eps; }
const Real pi = acos(-1.0L);

struct Point {
    Real x, y;
    Point() {}
    Point(Real x, Real y) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(Real k) const { return Point(x * k, y * k); }
    Point operator/(Real k) const { return Point(x / k, y / k); }
};
istream &operator>>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}
ostream &operator<<(ostream &os, Point p) {
    os << fixed << setprecision(10) << p.x << " " << p.y;
    return os;
}
bool sort_x(Point a, Point b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
bool sort_y(Point a, Point b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
bool sort_t(Point a, Point b) { return atan2(a.y, a.x) < atan2(b.y, b.x); }
Point rotate(Real theta, const Point &p) {
    return Point(cos(theta) * p.x - sin(theta) * p.y, sin(theta) * p.x + cos(theta) * p.y);
}
Real radian_to_degree(Real r) { return (r * 180.0 / pi); }
Real degree_to_radian(Real d) { return (d * pi / 180.0); }
Real get_angle(const Point &a, const Point &b, const Point &c) {
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.y, v.x), beta = atan2(w.y, w.x);
    if (alpha > beta)
        swap(alpha, beta);
    Real theta = (beta - alpha);
    return min(theta, 2 * pi - theta);
}
struct Line {
    Point a, b;
    Line() {}
    Line(Point a, Point b) : a(a), b(b) {}
    Line(Real A, Real B, Real C) { // Ax + By = C
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            a = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }
    Point vec() const { return b - a; }
};
struct Segment : Line {
    Segment() {}
    Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
    Point p;
    Real r;
    Circle() {}
    Circle(Point p, Real r) : p(p), r(r) {}
};
Real norm(const Point &a) { return a.x * a.x + a.y * a.y; }
Real abs(const Point &a) { return sqrt(norm(a)); }
Real cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
Real dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

Point project(Line l, Point p) {
    Real t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
Point reflect(Line l, Point p) { return p + (project(l, p) - p) * 2; }
bool parallel(Line a, Line b) { return eq(cross(a.vec(), b.vec()), 0.0); }
bool orthogonal(Line a, Line b) { return eq(dot(a.vec(), b.vec()), 0.0); }
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if (cross(b, c) > eps)
        return +1; // "COUNTER_CLOCKWISE"
    if (cross(b, c) < -eps)
        return -1; // "CLOCKWISE"
    if (dot(b, c) < 0)
        return +2; // "ONLINE_BACK"
    if (norm(b) < norm(c))
        return -2; // "ONLINE_FRONT"
    return 0;      // "ON_SEGMENT"
}
bool intersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }
bool intersect(const Line &l, const Line &m) { return !parallel(l, m) || abs(cross(l.vec(), m.b - l.a)) < eps; }
bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
bool intersect(const Line &l, const Segment &s) { return cross(l.vec(), s.a - l.a) * cross(l.vec(), s.b - l.a) < eps; }
Real distance(const Line &l, const Point &p);
bool intersect(const Circle &c, const Line &l) { return distance(l, c.p) <= c.r + eps; }
bool intersect(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < eps; }
bool intersect(const Segment &s, const Segment &t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
int intersect(const Circle &c, const Segment &l) {
    if (norm(project(l, c.p) - c.p) - c.r * c.r > eps)
        return 0;
    auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
    if (d1 < c.r + eps && d2 < c.r + eps)
        return 0;
    if ((d1 < c.r - eps && d2 > c.r + eps) || (d1 > c.r + eps && d2 < c.r - eps))
        return 1;
    const Point h = project(l, c.p);
    if (dot(l.a - h, l.b - h) < 0)
        return 2;
    return 0;
}
int intersect(Circle c1, Circle c2) {
    if (c1.r < c2.r)
        swap(c1, c2);
    Real d = abs(c1.p - c2.p);
    if (c1.r + c2.r < d)
        return 4; // do not cross
    if (eq(c1.r + c2.r, d))
        return 3; // circumscribed
    if (c1.r - c2.r < d)
        return 2; // intersect
    if (eq(c1.r - c2.r, d))
        return 1; // inscribed
    return 0;     // one circle includes another
}

Real distance(const Point &a, const Point &b) { return abs(a - b); }
Real distance(const Line &l, const Point &p) { return abs(p - project(l, p)); }
Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }
Real distance(const Segment &s, const Point &p) {
    Point r = project(s, p);
    if (intersect(s, r))
        return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
Real distance(const Segment &a, const Segment &b) {
    if (intersect(a, b))
        return 0;
    return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}
Real distance(const Line &l, const Segment &s) {
    if (intersect(l, s))
        return 0;
    return min(distance(l, s.a), distance(l, s.b));
}
Point crosspoint(const Line &l, const Line &m) {
    Real A = cross(l.vec(), m.vec());
    Real B = cross(l.vec(), l.b - m.a);
    if (eq(abs(A), 0.0) && eq(abs(B), 0.0))
        return m.a;
    return m.a + (m.b - m.a) * B / A;
}
Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }
pair<Point, Point> crosspoint(const Circle &c, const Line l) {
    Point pr = project(l, c.p);
    Point e  = (l.b - l.a) / abs(l.b - l.a);
    if (eq(distance(l, c.p), c.r))
        return {pr, pr};
    Real base = sqrt(c.r * c.r - norm(pr - c.p));
    return {pr - e * base, pr + e * base};
}
pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
    Line aa = Line(l.a, l.b);
    if (intersect(c, l) == 2)
        return crosspoint(c, aa);
    auto ret = crosspoint(c, aa);
    if (dot(l.a - ret.first, l.b - ret.first) < 0)
        ret.second = ret.first;
    else
        ret.first = ret.second;
    return ret;
}
pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
    Real d   = abs(c1.p - c2.p);
    Real a   = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Real t   = atan2(c2.p.y - c1.p.y, c2.p.x - c1.p.x);
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return {p1, p2};
}
vector<Point> convex_hull(vector<Point> &p) {
    int n = (int)p.size(), k = 0;
    if (n <= 2)
        return p;
    sort(p.begin(), p.end(), sort_x);
    vector<Point> ch(2 * n);
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < -eps)
            --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < -eps)
            --k;
    }
    ch.resize(k - 1);
    return ch;
}
#line 9 "test/geometry/reflection.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Line base(p1, p2);
    int q;
    cin >> q;
    vector<Point> r(q);
    for (int i = 0; i < q; ++i) {
        cin >> r[i].x >> r[i].y;
    }
    cout << fixed << setprecision(10);
    for (int i = 0; i < q; ++i) {
        Point ret = reflect(base, r[i]);
        cout << ret.x << " " << ret.y << "\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

