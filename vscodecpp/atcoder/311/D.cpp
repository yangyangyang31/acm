#include <bits/stdc++.h>

using namespace std;
#define int ll
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e18 + 10;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<char>> mp(200 + 1, vector<char>(200 + 1));
int vis[201][201];
int ans;

void dfs(int x, int y, int pos)
{
    if (mp[x][y] == '.')
        ans++;
    mp[x][y] = '@';
    if (pos == -1)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (mp[nx][ny] == '.' || mp[nx][ny] == '@')
                dfs(x + dx[i], y + dy[i], i);
        }
    }
    else
    {
        int nx = x + dx[pos], ny = y + dy[pos];
        if (mp[nx][ny] == '.' || mp[nx][ny] == '@')
            dfs(nx, ny, pos);
        else
        {
            if (!vis[x][y])
            {
                vis[x][y] = 1;
                for (int i = 0; i < 4; i++)
                {
                    if (i == pos)
                        continue;
                    int nx = x + dx[i], ny = y + dy[i];
                    if (mp[nx][ny] == '.' || mp[nx][ny] == '@')
                        dfs(x + dx[i], y + dy[i], i);
                }
            }
        }
    }
}

signed main(void)
{
    IOS;
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> mp[i][j];
    int sx = 2, sy = 2;
    dfs(sx, sy, -1);
    cout << ans << endl;
    return 0;
}
