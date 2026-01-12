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
        int n;
        cin >> n;
        if (n & 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}