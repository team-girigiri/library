class Dijkstra {
    int n;
    vector<vector<pair< int, double>>> adj;
    vector<double> d;

public:
    Dijkstra(int n) : n(n), adj(n), d(n, numeric_limits<double>::infinity()) {}

    void add_edge(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    void add_arc(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].emplace_back(b, w);
    }

    void run(int a) {
        d[a] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
        que.emplace(0, a);

        while (que.size()) {
            auto top = que.top();
            que.pop();
            int u = top.second;

            for (auto &p : adj[u]) {
                int v = p.first;
                double w = p.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    que.emplace(d[v], v);
                }
            }
        }
    }

    double dist(int a) {
        return d[a];
    }
};