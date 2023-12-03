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

const int N = 2e5 + 10;

int k, n, m, u, v, a[N], b[N], f[N], f1[N], q, x, y, l, lll;
map<pair<int, int>, bool> wh;
int find(int x) // 并查集
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> u >> v, f[find(u)] = find(v);
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i] >> b[i];
        wh[{find(a[i]), find(b[i])}] = wh[{find(b[i]), find(a[i])}] = 1; // 建立关系
    }
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        if (wh[{find(x), find(y)}])
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}