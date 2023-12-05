#include <bits/stdc++.h>

using namespace std;
#define int long long
#define itn int
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

const int N = 110;
int mp[N][N], dp[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;

int dfs(int x, int y)
{
    int ans = 0;
    st[x][y] = true;
    rep(i, 0, 3)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny])
            continue;
        else if (mp[x][y] > mp[nx][ny])
        {
            if (dp[nx][ny] == -1)
                ans = max(ans, dfs(nx, ny));
            else
                ans = max(ans, dp[nx][ny]);
        }
    }
    dp[x][y] = ans + 1;
    st[x][y] = false;
    return dp[x][y];
}

void solve()
{
    memset(dp, -1, sizeof dp);
    int ans = 1;
    cin >> n >> m;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> mp[i][j];
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {

            ans = max(ans, dfs(i, j));
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}

signed main(void)
{
    IOS;
    solve();
    return 0;
}