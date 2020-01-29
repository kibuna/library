template <typename T = lint>
struct SegmentTreeLazyAdd {
  private:
    using F = function<T(T, T)>;
    using G = function<int(int, int)>;
    int n;
    vector<T> node, lazy, width;
    vector<bool> lazyFlag;
    F func;
    G funcw;
    T unit;

  public:
    SegmentTreeLazyAdd(int sz, F func, G funcw, T unit) : func(func), funcw(funcw), unit(unit) {
        n = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, 0);
        lazyFlag.assign(2 * n - 1, false);
        width.assign(2 * n - 1, 1);
        for (int i = n - 2; i >= 0; --i) {
            width[i] = funcw(width[i * 2 + 1], width[i * 2 + 2]);
        }
    }
    SegmentTreeLazyAdd(vector<T> v, F func, G funcw, T unit) : func(func), funcw(funcw), unit(unit) {
        int sz = int(v.size());
        n      = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, 0);
        lazyFlag.assign(2 * n - 1, false);
        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = func(node[i * 2 + 1], node[i * 2 + 2]);
        width.assign(2 * n - 1, 1);
        for (int i = n - 2; i >= 0; --i) {
            width[i] = funcw(width[i * 2 + 1], width[i * 2 + 2]);
        }
    }
    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] += lazy[k] * width[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k]     = 0;
        }
    }
    // add x to nodes in [a, b)
    void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x; // +=
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
            return;
        } else {
            const int mid = (l + r) / 2;
            add(a, b, x, k * 2 + 1, l, mid);
            add(a, b, x, k * 2 + 2, mid, r);
            node[k] = func(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // get func() in [a, b)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return unit;
        if (a <= l && r <= b)
            return node[k];
        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(vl, vr);
    }
};
