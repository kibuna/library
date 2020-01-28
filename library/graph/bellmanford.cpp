template <typename T> // T : type of cost
struct BellmanFord {
    T inf = numeric_limits<T>::max(); // initial value, reused when clear() is called
    int n;                            // number of nodes
    vector<bool> negative;
    vector<T> dist; // distance from start node
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };
    vector<edge> edges;

    BellmanFord(int n) : n(n), negative(n, false), dist(n, inf){};

    // 0-indexed!
    void addEdge(int from, int to, T cost) { edges.emplace_back(from, to, cost); }

    // calculate dist[i] as a shortest distance from start to each node
    void build(int start) {
        dist[start] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }
    }

    // check whether there are negative cycles along the path of interest
    bool hasNegativeCycle(int end = -1) {
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to]     = dist[e.from] + e.cost;
                    negative[e.to] = true;
                }
                negative[e.to] = negative[e.to] | negative[e.from];
            }
        }
        if (end != -1)
            return negative[end];
        else {
            bool neg = false;
            for (int i = 0; i < n; ++i) {
                neg = neg | negative[i];
            }
            return neg;
        }
    }
};
