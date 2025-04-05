#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = vec[i - 1];
    }

    for (int l = n; l >= 1; l--) {
        for (int r = l + 1; r <= n; r++) {
            dp[l][r] = max(
                vec[l - 1] - dp[l + 1][r],
                vec[r - 1] - dp[l][r - 1]
            );
        }
    }
    //dp[l][r] stores the difference 

    cout << dp[1][n] << endl; 
    return 0;
}
