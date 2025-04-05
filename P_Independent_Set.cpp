#include <bits/stdc++.h>
using namespace std;

void fastInputOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastInputOutput();
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> radj(n); // reverse graph: for incoming edges
    vector<int> indegree(n, 0);

    // Read edges and build both normal and reverse graphs.
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        // u->v edge. (Assumption: the input specifies a tree/DAG.)
        adj[u].push_back(v);
        radj[v].push_back(u);
        indegree[v]++;
    }

    // Compute topological order.
    vector<int> topoSort;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for (auto &child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int node : topoSort)
    {
        if (adj[node].empty())
        {
            dp[node][1] = 1;
            dp[node][0] = 0;
        }
    }

    // Process nodes in reverse topological order (bottom-up).
    // Now, for each node, add contributions from every incoming edge (i.e. from its parent)
    for (int i = 1; i < topoSort.size(); i++)
    {
        int node = topoSort[i];
        for (auto &parent : radj[node])
        {
            // Accumulate dp from node into parent's dp.
            dp[parent][1] += dp[node][0];
            dp[parent][0] += dp[node][0] + dp[node][1];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (radj[i].empty())
        {
            answer += dp[i][0] + dp[i][1];
        }
    }
    cout << answer << "\n";
    return 0;
}