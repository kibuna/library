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


# :warning: library/geometry/geometry.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1a4ce6642786277d76dc97dbc3cc79c6">library/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/geometry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 23:34:29+09:00




## Required by

* :warning: <a href="../../test/geometry/projection.cpp.html">test/geometry/projection.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const double eps = 1e-10;
inline bool eq(double a, double b) { return fabs(a - b) < eps; }
const double pi = acos(-1);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
};
Point rotate(double theta, const Point &p) {
    return Point(cos(theta) * p.x - sin(theta) * p.y, sin(theta) * p.x + cos(theta) * p.y);
}
double radian_to_degree(double r) { return (r * 180.0 / pi); }
double degree_to_radian(double d) { return (d * pi / 180.0); }

struct Line {
    Point a, b;
    Line() {}
    Line(Point a, Point b) : a(a), b(b) {}
    Line(double A, double B, double C) { // Ax + By = C
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            a = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }
};

struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p(p), r(r) {}
};
double norm(const Point &a) { return a.x * a.x + a.y * a.y; }
double abs(const Point &a) { return sqrt(norm(a)); }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

Point projection(Line l, Point p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
Point reflect(Line l, Point p) { return p + (projection(l, p) - p) * 2; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/geometry/geometry.cpp"
const double eps = 1e-10;
inline bool eq(double a, double b) { return fabs(a - b) < eps; }
const double pi = acos(-1);

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
};
Point rotate(double theta, const Point &p) {
    return Point(cos(theta) * p.x - sin(theta) * p.y, sin(theta) * p.x + cos(theta) * p.y);
}
double radian_to_degree(double r) { return (r * 180.0 / pi); }
double degree_to_radian(double d) { return (d * pi / 180.0); }

struct Line {
    Point a, b;
    Line() {}
    Line(Point a, Point b) : a(a), b(b) {}
    Line(double A, double B, double C) { // Ax + By = C
        if (eq(A, 0))
            a = Point(0, C / B), b = Point(1, C / B);
        else if (eq(B, 0))
            a = Point(C / A, 0), b = Point(C / A, 1);
        else
            a = Point(0, C / B), b = Point(C / A, 0);
    }
};

struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p(p), r(r) {}
};
double norm(const Point &a) { return a.x * a.x + a.y * a.y; }
double abs(const Point &a) { return sqrt(norm(a)); }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

Point projection(Line l, Point p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
Point reflect(Line l, Point p) { return p + (projection(l, p) - p) * 2; }

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

