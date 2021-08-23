// Kruskal’s Algorithm + Union => Minimum Spanning Tree
int findRoot(vector<int>& roots, int i) {
    return i == roots[i] ? i : roots[i] = findRoot(roots, roots[i]);
}
int minimumCost(int N, vector<vector<int>>& connections) {
    vector<int> roots(N + 1), cnt(N + 1, 1);
    for (int i = 0; i <= N; ++i) roots[i] = i;
    sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    int res = 0, n = N;
    for (const vector<int>& c : connections) {
        int r1 = findRoot(roots, c[0]), r2 = findRoot(roots, c[1]);
        if (r1 != r2) {
            res += c[2];
            if (cnt[r1] >= cnt[r2]) {
                roots[r2] = r1;
                cnt[r1] += cnt[r2];
            } else {
                roots[r1] = r2;
                cnt[r2] += cnt[r1];
            }
            --n;
        }
    }
    return n == 1 ? res : -1;
}
