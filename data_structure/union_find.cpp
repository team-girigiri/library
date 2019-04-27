struct UnionFind {
    int n, cnt;
    vector<int> par, rank, sz;

    UnionFind(int n) : n(n), cnt(n), par(n), rank(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return sz[find(x)]; }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
        cnt--;
    }
};