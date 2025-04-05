#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1), dp(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
