#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

#include "../../library/graph/warshallfloyd.cpp"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    vector<vector<lint>> dist(v, vector<lint>(v, inf));
    for (int i = 0; i < v; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < e; ++i) {
        lint s, t, d;
        cin >> s >> t >> d;
        chmin(dist[s][t], d);
    }
    warshallFloyd<lint, true>(dist, inf);
    bool has_negative_loop = false;
    for (int i = 0; i < v; ++i) {
        if (dist[i][i] < 0) {
            has_negative_loop = true;
            break;
        }
    }
    if (has_negative_loop) {
        cout << "NEGATIVE CYCLE"
             << "\n";
    } else {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (j != 0)
                    cout << " ";
                if (dist[i][j] == inf)
                    cout << "INF";
                else
                    cout << dist[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}