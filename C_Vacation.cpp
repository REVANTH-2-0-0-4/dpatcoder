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
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    f(i, n)
    {
        f(j, 3)
        {
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0] = vec[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = vec[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = vec[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = vec[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    int result = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << result << endl;
    return 0;
}