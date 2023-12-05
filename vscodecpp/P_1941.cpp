#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

struct node
{
    int a, b, c;
};

bool cmp(node a, node b)
{
    return a.a < b.a;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1005));
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    vector<node> a(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    sort(a.begin() + 1, a.end(), cmp);
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            dp[i][j] = inf;
        for (int j = x[i] + 1; j <= m + x[i]; j++)
            dp[i][j] = min(dp[i][j - x[i]] + 1, dp[i - 1][j - x[i]] + 1);
        for (int j = m + 1; j <= m + x[i]; j++)
            dp[i][m] = min(dp[i][m], dp[i][j]);
        for (int j = y[i]; j <= m - y[i]; j++)
            dp[i][j] = min(dp[i][j], dp[i - 1][j - y[i]]);
        if (i == a[cnt].a)
        {
            int ans = inf;
            for (int j = 0; j <= a[cnt].b; j++)
                dp[i][j] = inf;
            for (int j = a[cnt].c; j <= m; j++)
                dp[i][j] = inf;
            for (int j = a[cnt].b; j <= a[cnt].c; j++)
                ans = min(ans, dp[i][j]);
            if (ans == inf)
            {
                cout << 0 << endl;
                cout << cnt - 1 << endl;
                return;
            }
            cnt++;
        }
    }
    int ans = inf;
    for (int i = 1; i <= m; i++)
        ans = min(ans, dp[n][i]);
    cout << 1 << endl;
    cout << ans << endl;
}

signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}