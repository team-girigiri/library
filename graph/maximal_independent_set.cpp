vector<bool> maximalIndependentSet(const vector<vector<int>> &adj,
                                   const int limit = 1000) {
    mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
    int n = adj.size();
    vector<int> pm(n);
    iota(pm.begin(), pm.end(), 0);

    auto start = chrono::system_clock::now();

    vector<bool> ret;
    int sz = 0;

    int cnt = 0;

    while (1) {
        cnt++;
        if (cnt >> 10 & 1) {
            auto now = chrono::system_clock::now();
            if (chrono::duration_cast<chrono::milliseconds>(now - start)
                    .count() > limit)
                break;
        }

        vector<bool> tmp(n);
        int s = 0;

        for (int a : pm) {
            bool ok = true;
            for (int b : adj[a]) {
                if (tmp[b]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                tmp[a] = true;
                s++;
            }
        }

        if (s > sz) {
            sz = s;
            ret = tmp;
        }

        shuffle(pm.begin(), pm.end(), rnd);
    }

    cerr << "tried " << cnt << " times" << endl;
    return ret;
}
