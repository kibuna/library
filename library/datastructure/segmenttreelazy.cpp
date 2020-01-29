template <typename T = lint>
struct SegmentTreeLazy {
  private:
    using F = function<T(T, T)>;
    int n;
    vector<T> node, lazy;
    vector<bool> lazyFlag;
    F func;
    T unit;

  public:
    SegmentTreeLazy(int sz, F func, T unit) : func(func), unit(unit) {
        n = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, unit);
        lazyFlag.resize(2 * n - 1, false);
    }
    SegmentTreeLazy(vector<T> v, F func, T unit) : func(func), unit(unit) {
        int sz = int(v.size());
        n      = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1, unit);
        lazy.resize(2 * n - 1, unit);
        lazyFlag.resize(2 * n - 1, false);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = func(node[i * 2 + 1], node[i * 2 + 2]);
    }
    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] = lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }
    // replace nodes with x in [a, b)
    void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b) {
            lazy[k]     = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        } else {
            const int mid = (l + r) / 2;
            update(a, b, x, 2 * k + 1, l, mid);
            update(a, b, x, 2 * k + 2, mid, r);
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
