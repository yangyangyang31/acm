#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 10;

int n, m, t;
set<int> G[N];
int d[N];
int ans;
signed main()
{
    // freopen("*.in", "r", stdin);
    // freopen("*.out", "w", stdout);
    cin >> n >> m;
    ans = n;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int u, v;
            cin >> u >> v;
            G[u].insert(v);
            G[v].insert(u);
            ans -= (d[u] == 0);
            ans -= (d[v] == 0);
            d[u]++;
            d[v]++;
        }
        else
        {
            int x;
            cin >> x;
            for (auto i : G[x])
            {
                d[i]--;
                ans += (d[i] == 0);
                G[i].erase(x);
            }
            G[x].clear();
            ans += (d[x] != 0);
            d[x] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
