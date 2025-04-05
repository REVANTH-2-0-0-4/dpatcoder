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

void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void fun(vector<vector<int>> &vec, vector<vector<int>> &visited,int &ans){
    
}

int32_t main() {
    fastInputOutput();
    int n;cin>>n;
    vector<vector<int>> vec(n,vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>vec[i][j];
        }
    }
    int ans= 0;
    vector<vector<int>> visited (n,vector<int>(n, 0));
    fun(vec,visited,ans);
    return 0;
}