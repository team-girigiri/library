struct Hungarian {
    const int INF = 1e9;
    int n, p, q;
    vector<vector<int>> mat;
    vector<int> fx, fy, x, y;

    Hungarian(const vector<vector<int>> &mat)
        : n(mat.size()), mat(mat), fx(mat.size(), INF), fy(mat.size()), x(mat.size(), -1), y(mat.size(), -1) {}

    int run() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fx[i] = max(fx[i], mat[i][j]);
            }
        }

        for (int i = 0; i < n;) {
            vector<int> t(n, -1), s(n + 1, i);
            for (p = q = 0; p <= q && x[i] < 0; p++) {
                for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {
                    if (fx[k] + fy[j] == mat[k][j] && t[j] < 0) {
                        s[++q] = y[j];
                        t[j] = k;
                        if (s[q] < 0) {
                            for (p = j; p >= 0; j = p) {
                                y[j] = k = t[j];
                                p = x[k];
                                x[k] = j;
                            }
                        }
                    }
                }
            }
            if (x[i] < 0) {
                int d = INF;
                for (int k = 0; k <= q; k++) {
                    for (int j = 0; j < n; j++) {
                        if (t[j] < 0) {
                            d = min(d, fx[s[k]] + fy[j] - mat[s[k]][j]);
                        }
                    }
                }
                for (int j = 0; j < n; j++) {
                    fy[j] += (t[j] < 0 ? 0 : d);
                }
                for (int k = 0; k <= q; k++) {
                    fx[s[k]] -= d;
                }
            } else {
                i++;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += mat[i][x[i]];
        }
        return ret;
    }

    int match_y(int k) { return x[k]; }

    int match_x(int k) { return y[k]; }
};