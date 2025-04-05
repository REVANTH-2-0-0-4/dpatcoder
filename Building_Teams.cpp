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
vector<int> parent;
vector<int> height;
void setup(int node)
{
    parent[node] = node;
    height[node] = 1;
}
int find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (height[a] == height[b])
            height[a]++;
        if (height[a] < height[b])
            swap(a, b);
        parent[b] = a;
    }
}

void fastInputOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main()
{
    fastInputOutput();
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    height.resize(n + 1, 1);
    vector<vector<int>> adj;
    for (int i = 1; i <= n; i++)
    {
        setup(i);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (i == 0)
        {
            parent[x] = 1;
            parent[y] = 2;
            continue;
        }
        if (find(x) == 1)
        {
            if (find(y) == 1)
            {
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            else if (find(y) == 2)
            {
                continue;
            }
            else
            {
                parent[y] = 2;
            }
        }

        else if (find(x) == 2)
        {
            if (find(y) == 2)
            {
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            else if (find(y) == 1)
            {
                continue;
            }
            else
            {
                parent[y] = 1;
            }
        }
        else if (find(y) == 1)
        {
            if (find(x) == 1)
            {
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            else if (find(x) == 2)
            {
                continue;
            }
            else
            {
                parent[x] = 2;
            }
        }
        else if (find(y) == 2)
        {
            if (find(x) == 2)
            {
                cout << "IMPOSSIBLE" << endl;
                break;
            }
            else if (find(x) == 1)
            {
                continue;
            }
            else
            {
                parent[x] = 1;
            }
        }
        else
        {
            parent[x] = 1;
            parent[y] = 2;
            continue;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 1 || parent[i] == 2)
        {
            cout << parent[i] << " ";
        }
        else
        {
            cout << 1 << " ";
        }
    }
    cout << endl;

    return 0;
}