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


// this is a problem similar to bellman-ford algorithm

using namespace std;

void fastInputOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
int sum(vector<int> &vec, int l, int r)
{
    int sum  = 0;
    for(int i =  l ; i <= r; i++)
    {
        sum += vec[i];
    }
    return sum;
}
int32_t main()
{
    fastInputOutput();
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i - 1];
    }
    // f(i, n) cin >> vec[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            // cout<< " test " << i << " " << j << endl;
            for (int k = i; k < j; k++)
            {
                if (dp[i][k] != LLONG_MAX && dp[k + 1][j] != LLONG_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum(vec, i-1, j-1));
                }
            }
            // cout << " dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
