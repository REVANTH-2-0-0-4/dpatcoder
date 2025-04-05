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

int32_t main()
{
    fastInputOutput();
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> values[i];
    }

    int max_value = accumulate(all(values), 0);

    vector<vector<int>> dp(n + 1, vector<int>(max_value + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_value; j++)
        {
            if (j < values[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], wt[i - 1] + dp[i - 1][j - values[i - 1]]); // Take the i-th item
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= max_value; j++)
    {
        if (dp[n][j] <= w)
        {
            result = max(result, j);
        }
    }

    cout << result << endl;
    return 0;
}