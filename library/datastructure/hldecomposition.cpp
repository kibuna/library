#include "segmenttree.cpp"
template <typename T = lint>
class HLDecomposition {
    using F = function<T(T, T)>;
    void dfs_sz(int v) {
        for (int &u : edges[v])
            if (u == par[v])
                swap(u, edges[v].back());
        if (~par[v])
            edges[v].pop_back();

        for (int &u : edges[v]) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[edges[v][0]])
                swap(u, edges[v][0]);
        }
    }
    void dfs_hld(int v, int c, int &pos) {
        vid[v]      = pos++;
        inv[vid[v]] = v;
        type[v]     = c;
        for (int u : edges[v]) {
            if (u == par[v])
                continue;
            head[u] = (u == edges[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
    }
    bool built;

  public:
    vector<vector<int>> edges;
    vector<int> vid, head, sub, par, dep, inv, type;
    F f;
    T unit;
    SegmentTree<T> segTree;

    HLDecomposition(int n, F f, T unit)
        : built(false), edges(n), vid(n, -1), head(n), sub(n, 1), par(n, -1), dep(n, 0), inv(n), type(n), f(f),
          unit(unit), segTree(n, f, unit) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void build(vector<int> rs = {0}) {
        int c = 0, pos = 0;
        for (int r : rs) {
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, c++, pos);
        }
        built = true;
    }

    void assign(vector<T> nodes) {
        assert(nodes.size() == vid.size());
        vector<T> v(nodes.size());
        for (int i = 0; i < (int)nodes.size(); ++i) {
            v[vid[i]] = nodes[i];
        }
        segTree = SegmentTree<T>(v, f, unit);
    }

    int lca(int u, int v) {
        assert(built);
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            if (head[u] == head[v])
                return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

    void update(int k, T x) { segTree.update(vid[k], x); }

    // query for each vertex
    // [l, r] <- attention!! closed section (path) on the tree
    T query(int u, int v) {
        assert(built);
        T ret = unit;
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            ret = f(ret, segTree.query(max(vid[u], vid[head[v]]), vid[v] + 1));
            if (head[u] != head[v])
                v = par[head[v]];
            else
                return ret;
        }
    }

    // query for each edge: exclude lca's value
    // [l, r] <- attention!! closed section (path) on the tree
    T query_edge(int u, int v) {
        assert(built);
        T ret = unit;
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            if (head[u] != head[v]) {
                ret = f(ret, segTree.query(vid[head[v]], vid[v] + 1));
                v   = par[head[v]];
            } else {
                if (u != v)
                    ret = f(ret, f(vid[u] + 1, vid[v] + 1));
                return ret;
            }
        }
    }
};
