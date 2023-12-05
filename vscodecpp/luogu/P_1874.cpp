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

void solve()
{
    string a, b;
    cin >> a;
    int n = a.size();
    a = ' ' + a;
    b += ' ';
    for (int i = n; i >= 1; i--)
        b += a[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j]);
            if (a[i] == b[j])
            {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }
    cout << dp[n][n] << endl;
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
