#include <bits/stdc++.h>
using namespace std;
#define int long long

void fastInputOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main()
{
    fastInputOutput();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    // Read edges: (assuming n-1 edges for a tree or forest)
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    
    // Get topological order and record roots (nodes with indegree 0)
    queue<int> q;
    vector<int> ans;
    set<int> roots;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            roots.insert(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
                q.push(child);
        }
    }
    
    // dp[node][0]: ways when node is not chosen
    // dp[node][1]: ways when node is chosen
    // Initialise all nodes to 1.
    vector<vector<int>> dp(n + 1, vector<int>(2, 1));
    
    // Process nodes in reverse topological order (from leaves up)
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int node = ans[i];
        for (auto child : adj[node])
        {
            dp[node][0] *= (dp[child][0] + dp[child][1]);
            dp[node][1] *= dp[child][0];
        }
    }
    
    int result = 1;
    for (auto r : roots)
    {
        result *= (dp[r][0] + dp[r][1]);
    }
    
    cout << result << "\n";
    return 0;
}
