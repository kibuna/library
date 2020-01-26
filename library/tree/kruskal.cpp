#include "../datastructure/unionfind.cpp"

// Kruskal algorithm: build minimum spanning tree
template <typename T>
struct Kruskal {
    struct edge {
        int from, to, used;
        T cost;
        edge(int from_, int to_, T cost_) : from(from_), to(to_), used(0), cost(cost_) {}
        bool operator<(const edge &e) const { return cost < e.cost; }
    };
    vector<edge> es;
    UnionFind uf;
    Kruskal(int n) : uf(n + 1) {}
    void addEdge(int f, int t, T c) { es.emplace_back(f, t, c); }
    T build() {
        sort(es.begin(), es.end());
        T res = 0;
        for (auto &e : es) {
            if (!uf.isSame(e.from, e.to)) {
                res += e.cost;
                uf.unite(e.from, e.to);
                e.used = 1;
            }
        }
        return res;
    }
};
