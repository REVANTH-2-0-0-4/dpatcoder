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
const int INF = 1e18 + 5;
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
    int k;
    cin >> k;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    dp[1] = 0;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {

            if (i - j >= 1)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(height[i - j - 1] - height[i - 1]));
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}