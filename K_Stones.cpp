#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> moves(n);
    for (int i = 0; i < n; i++)
    {
        cin >> moves[i];
    }

    vector<vector<bool>> dp(2, vector<bool>(k + 1, false));

    dp[0][0] = false;
    dp[1][0] = false;
    // dp[i][j] defines whether the current player  ( 0 for taro , and 1 for jira (subject to correction )) can win from the following state or not
    for (int j = 1; j <= k; j++)
    {
        for (int t = 0; t < 2; t++)
        {
            bool canWin = false;
            for (int move : moves)
            {
                if (j >= move && !dp[1 - t][j - move])
                {
                    canWin = true;
                    break;
                }
            }
            dp[t][j] = canWin;
        }
    }

    cout << (dp[0][k] ? "First" : "Second") << endl;

    return 0;
}
