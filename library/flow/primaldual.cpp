// @see https://ei1333.github.io/luzhiled/snippets/graph/primal-dual.html
template <typename T>
struct PrimalDual {
    struct edge {
        int to;
        T cap, cost;
        int rev;
        edge() {}
        edge(int to, T cap, T cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };
    const T inf = numeric_limits<T>::max() / 2;
    vector<vector<edge>> G;
    vector<T> h, dist;
    vector<int> prevv, preve;

    PrimalDual() {}
    PrimalDual(int n) : G(n), h(n), dist(n), prevv(n), preve(n) {}

    void addEdge(int from, int to, T cap, T cost) {
        G[from].emplace_back(to, cap, cost, G[to].size());
        G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
    }

    void dijkstra(int s) {
        struct P {
            T first;
            int second;
            P(T first, int second) : first(first), second(second) {}
            bool operator<(const P &a) const { return first > a.first; }
        };
        priority_queue<P> que;
        fill(dist.begin(), dist.end(), inf);

        dist[s] = 0;
        que.emplace(dist[s], s);
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap == 0)
                    continue;
                if (dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to]  = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    T flow(int s, int t, T f, int &ok) {
        T res = 0;
        fill(h.begin(), h.end(), 0);
        while (f > 0) {
            dijkstra(s);
            if (dist[t] == inf)
                return ok = 0;

            for (int v = 0; v < (int)h.size(); v++)
                h[v] += dist[v];

            T d = f;
            for (int v = t; v != s; v = prevv[v])
                d = min(d, G[prevv[v]][preve[v]].cap);

            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        ok = 1;
        return res;
    }
};
