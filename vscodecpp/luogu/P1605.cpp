#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int sx, sy, fx, fy, ans = 0;
int n, m, t;
int mp[10][10];
bool st[10][10];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    st[x][y] = true;
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny])
            continue;
        if (mp[nx][ny] == 0)
        {
            st[nx][ny] = true;
            dfs(nx, ny);
            st[nx][ny] = false;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}