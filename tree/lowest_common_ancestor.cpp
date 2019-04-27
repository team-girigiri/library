template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    vector<int> lookup;

    SparseTable(const vector<T> &v) {
        int b = 0;
        while ((1 << b) <= v.size()) b++;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < v.size(); i++) {
            st[0][i] = v[i];
        }
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <= 1 << b; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        lookup.resize(v.size() + 1);
        for (int i = 2; i < lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    T query(int l, int r) {
        int b = lookup[r - l];
        return min(st[b][l], st[b][r - (1 << b)]);
    }
};

struct LCA {
    int n, k = 0;
    vector<vector<int>> adj;
    vector<int> vs, depth, id, D;
    SparseTable<pair<int, int>> *st;

    void dfs(int v, int p, int d) {
        id[v] = k;
        vs[k] = v;
        depth[k++] = d;
        D[v] = d;
        for (int s : adj[v]) {
            if (s != p) {
                dfs(s, v, d + 1);
                vs[k] = v;
                depth[k++] = d;
            }
        }
    }

    LCA(const vector<vector<int>> &adj)
        : n(adj.size()), adj(adj), vs(2 * adj.size() - 1), depth(2 * adj.size() - 1), id(adj.size()), D(adj.size()) {
        dfs(0, -1, 0);
        vector<pair<int, int>> ds;
        for (int i = 0; i < depth.size(); i++) {
            ds.emplace_back(depth[i], i);
        }
        st = new SparseTable<pair<int, int>>(ds);
    }

    int lca(int u, int v) { return vs[st->query(min(id[u], id[v]), max(id[u], id[v]) + 1).second]; }

    int dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)]; }
};