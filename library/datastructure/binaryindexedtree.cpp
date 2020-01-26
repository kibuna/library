// Binary Indexed Tree / Fenwick tree
// calculate partial sum in O(logN)
// update single datum in O(logN)
// lower_bound is binary search O(logN)
// 0-indexed!!!
template <typename T = int>
struct BinaryIndexedTree {
    int n;
    vector<T> bit;
    BinaryIndexedTree(int n_) : n(n_), bit(n_ + 1, 0) {}
    BinaryIndexedTree(vector<T> const &init) : n(init.size()), bit(init.size() + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            bit[i] = init[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            if (i + (i & -i) <= n)
                bit[i + (i & -i)] += bit[i];
        }
    }
    T sum(int i) {
        i++;
        T s = 0;
        for (int x = i; x > 0; x -= (x & -x))
            s += bit[x];
        return s;
    }
    void add(int i, T a) {
        i++;
        if (i == 0)
            return;
        for (int x = i; x <= n; x += (x & -x))
            bit[x] += a;
    }
    int lower_bound(int w) {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    int upper_bound(int w) {
        if (w < 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] <= w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
};
