#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define int long long
int n;
vector<vector<int>> vec;
vector<long long> dp;

/**
 * Recursively counts the number of valid matchings using dynamic programming.
 *              An integer bitmask representing the columns that have already been matched.
 *             Each bit in the mask corresponds to a column; if a bit is set (1), it means that
 *             the corresponding column has been matched. The number of matched columns,
 *             determined by __builtin_popcount(mask), indicates the current row index being processed.
 *             In other words, mask is not the row number itself, but the count of set bits in mask
 *             signifies which row is being processed next.
 *              The total number of valid matching configurations starting from the current state.
 *
 * The algorithm operates by matching one row at a time. The current row to match is determined by the
 * number of set bits in mask (which is equal to __builtin_popcount(mask)). For each unmatched column,
 * it checks whether a match is allowed (vec[row][col] == 1) and then recurses by setting the corresponding
 * bit in mask. Intermediate results are cached in the dp array to avoid recomputation.
 */
long long countMatchings(int mask) {
    int row = __builtin_popcount(mask);
    if (row == n) return 1;
    if (dp[mask] != -1) return dp[mask];
    
    long long ways = 0;
    for (int col = 0; col < n; col++) {
        if (!(mask & (1 << col)) && vec[row][col] == 1) {
            ways += countMatchings(mask | (1 << col));
            ways %= mod;
        }
    }
    dp[mask] = ways;
    return ways;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vec.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }
    
    dp.assign(1 << n, -1);
    cout << countMatchings(0) << "\n";
    return 0;
}



