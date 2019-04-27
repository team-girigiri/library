class FordFulkerson {
    const int INF = 1e9;
    struct edge {
        int to, cap, rev;
    };

    int n;
    vector<vector<edge>> G;
    vector<bool> used;

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;

        for (edge& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

   public:
    FordFulkerson(int n) : n(n), G(n), used(n) {}

    void add_edge(int from, int to, int cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            used.assign(n, false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};