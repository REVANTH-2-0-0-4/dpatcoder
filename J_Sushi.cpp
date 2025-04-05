#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> vec(n);
    int c1 = 0, c2 = 0, c3 = 0;
    
    for (int i = 0; i < n; i++){
        cin >> vec[i];
        if(vec[i] == 1) c1++;
        else if(vec[i] == 2) c2++;
        else if(vec[i] == 3) c3++;
    }
    
    // Create DP array with dimensions (c1+1) x (c2+1) x (c3+1)
    vector<vector<vector<double>>> dp(c1+1, 
        vector<vector<double>>(c2+1, vector<double>(c3+1, 0.0)));
    
    // Base case: dp[0][0][0] = 0 (already set)

    // Iterate over all possible states.
    // It's typical to iterate by total non-empty dishes: s = i + j + k
    for (int s = 1; s <= n; s++){
        for (int i = 0; i <= c1; i++){
            for (int j = 0; j <= c2; j++){
                int k = s - i - j; // because i + j + k = s
                if (k < 0 || k > c3) continue;
                
                // dp[i][j][k] = (n + i*dp[i-1][j][k] + j*dp[i+1][j-1][k] + k*dp[i][j+1][k-1]) / (i+j+k)
                double sum = i + j + k;
                double expected = n; // the cost of the current move
                if (i > 0)
                    expected += i * dp[i-1][j][k];
                if (j > 0 && i+1 <= c1) // dish with 2 sushi becomes dish with 1 sushi
                    expected += j * dp[i+1][j-1][k];
                if (k > 0 && j+1 <= c2) // dish with 3 sushi becomes dish with 2 sushi
                    expected += k * dp[i][j+1][k-1];
                
                dp[i][j][k] = expected / sum;
            }
        }
    }
    
    cout << fixed << setprecision(10) << dp[c1][c2][c3] << "\n";
    return 0;
}
