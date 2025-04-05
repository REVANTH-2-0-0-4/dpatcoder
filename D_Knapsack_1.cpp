#include <bits/stdc++.h>

#define debug(x) cerr << "[" << #x << "] = " << (x) << '\n';

#define int long long
#define all(x) x.begin(), x.end()
#define f(i, n) for (int i = 0; i < n; i++)
#define r(dt, name) for (auto &dt : name)
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define debvar(x) cerr << #x << " = " << (x) << " | ";
#define debline cerr << "Line: " << __LINE__ << "\n";
#define check(msg) cerr << "check: " << msg << " at line: " << __LINE__ << '\n';

using namespace std;

void fastInputOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
int topDownKnapsack(vector<int> &wt, vector<int> &val, int n, int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][w];
}

int32_t main()
{
    fastInputOutput();
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        cin >> val[i];
    }
    cout << topDownKnapsack(wt, val, n, w);
    return 0;
}