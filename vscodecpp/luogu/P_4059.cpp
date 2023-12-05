#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 1e18;

const int N = 3020;
int d[5][5];
int dp[N][N][3];

void solve()
{
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    int n = a.size() - 1, m = b.size() - 1;
    map<char, int> st;
    st['A'] = 1;
    st['T'] = 2;
    st['G'] = 3;
    st['C'] = 4;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cin >> d[i][j];
    int aa, bb;
    cin >> aa >> bb;
    vector<int> x(n + 1), y(m + 1);
    for (int i = 1; i <= n; i++)
        x[i] = st[a[i]];
    for (int i = 1; i <= m; i++)
        y[i] = st[b[i]];
    for (int i = max(n, m); i; i--)
    {
        dp[0][i][0] = dp[i][0][0] = dp[0][i][2] = dp[i][0][1] = -inf;
        dp[0][i][1] = dp[i][0][2] = -aa - bb * (i - 1);
    }
    dp[0][0][1] = dp[0][0][2] = -inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            dp[i][j][0] = max(max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]), dp[i - 1][j - 1][2]) + d[x[i]][y[j]];
            dp[i][j][1] = max(max(dp[i][j - 1][0] - aa, dp[i][j - 1][1] - bb), dp[i][j - 1][2] - aa);
            dp[i][j][2] = max(max(dp[i - 1][j][0] - aa, dp[i - 1][j][2] - bb), dp[i - 1][j][1] - aa);
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[n][m][i]);
    cout << ans << endl;
}

signed main(void)
{
    IOS;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
