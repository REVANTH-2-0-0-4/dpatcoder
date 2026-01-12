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
    int T = 1;
    cin >> T;
    while (T--)
    {
       string s;
       cin>>s;
        int ans = 0;
        int last = -1;
        // cout<<s<<endl;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                last = i;
            }
        }
        for(int i = 0  ; i < last;i++){
            if(s[i] != '0'){
                ans++;
            }
        }
        for(int i = last+1 ; i < s.size();i++){
            ans++;
        }
        cout<<ans<<endl;

    }
    return 0;
}