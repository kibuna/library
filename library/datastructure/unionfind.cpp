struct UnionFind {
    vector<int> rank, parent, size;

    // +1 for 1-indexed nodes
    UnionFind(int n) : rank(n + 1, 0), parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0); // parent is itself
    }
    int root(int x) {
        if (x != parent[x]) {
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) { return link(root(x), root(y)); }
    bool link(int x, int y) {
        if (x == y)
            return false;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
        return true;
    }
    int getSize(int x) { return size[root(x)]; }
};
