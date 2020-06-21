// ref: https://github.com/beet-aizu/library/blob/master/flow/dinic.cpp
template <typename T, bool directed>
struct Dinic {
    struct edge {
        int to;
        T cap;   // capacity of the edge
        int rev; // index for to->from edge
        edge() {}
        edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {}
    };
    T inf = numeric_limits<T>::max();
    vector<vector<edge>> G;
    vector<int> level, iter;
    Dinic(int n) : G(n), level(n), iter(n) {}

    void addEdge(int from, int to, T cap) {
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed ? 0 : cap, G[from].size() - 1);
    }
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.emplace(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (edge &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.emplace(e.to);
                }
            }
        }
    }
    T dfs(int v, int t, T f) {
        if (v == t)
            return f;
        for (int &i = iter[v]; i < int(G[v].size()); ++i) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d == 0)
                    continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T maxFlow(int s, int t, T lim) {
        T fl = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0 || lim == 0)
                break;
            fill(iter.begin(), iter.end(), 0);
            while (true) {
                T f = dfs(s, t, lim);
                if (f == 0)
                    break;
                fl += f;
                lim -= f;
            }
        }
        return fl;
    }
    // returns maximum flow from s to t
    T maxFlow(int s, int t) { return maxFlow(s, t, inf); }
};