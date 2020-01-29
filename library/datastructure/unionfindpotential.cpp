template <class Abel>
struct UnionFindPotential {
    vector<int> parent, rank;
    vector<Abel> diff_weight;

    UnionFindPotential(int n = 1, Abel SUM_UNITY = 0)
        : parent(n + 1), rank(n + 1, 0), diff_weight(n + 1, SUM_UNITY) {
        iota(parent.begin(), parent.end(), 0);
    }
    int root(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            int r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        parent[y] = x;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
};
