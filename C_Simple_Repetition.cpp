#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canPartition(int x, int k, const vector<int>& a) {
    if (x == 0) return true;
    int n = a.size();
    int segments = 0;
    
    vector<bool> found(x, false);
    int temp = 0;
    
    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (val < x && !found[val]) {
            found[val] = true;
            temp++;
        }
        if (temp == x) {
            segments++;
            fill(found.begin(), found.end(), false);
            temp = 0;
        }
    }
    
    return segments >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        
        int lo = 0, hi = n + 2;
        while(lo + 1 < hi){
            int mid = (lo + hi) / 2;
            if (canPartition(mid, k, a))
                lo = mid;
            else
                hi = mid;
        }
        
        cout << lo << "\n";
    }
    
    return 0;
}
