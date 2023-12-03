#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 350;
char mp[N][N];
int step[N][N];
bool st[N][N], s[N][N];
int n, m, tmm, x, y, tt, ex, ey;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<pii> v;
vector<int> vv;
pii pre[N][N];

void bfs(int a, int b)
{
    queue<pii> q;
    st[a][b] = true; // 表示1号点已经被遍历过
    q.push({a, b});

    while (q.size())
    {
        pii t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        if (step[x][y] > tmm)
            return;
        st[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny] || mp[nx][ny] == '#')
                continue;
            q.push({nx, ny});
            step[nx][ny] = step[x][y] + 1;
            st[nx][ny] = true;
            pre[nx][ny] = {x, y};
            if (mp[nx][ny] == 'o')
                v.push_back({nx, ny});
            if (mp[nx][ny] == 'G')
                tt = step[nx][ny];
        }
    }
}

int main()
{
    cin >> n >> m >> tmm;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'S')
                x = i, y = j;
            if (mp[i][j] == 'G')
                ex = i, ey = j;
        }
    }
    bfs(x, y);
    if (tt == 0 || tt > tmm)
    {
        cout << -1 << endl;
        return 0;
    }
    s[ex][ey] = true;
    while (1)
    {
        pii t = pre[ex][ey];
        if (t.first == 0 && t.second == 0)
            break;
        ex = t.first, ey = t.second;
        s[ex][ey] = true;
    }
    for (auto i : v)
    {
        int sum = 0;
        int x = i.first, y = i.second;
        while (1)
        {
            if (s[x][y])
                break;
            sum++;
            pii t = pre[x][y];
            x = t.first, y = t.second;
        }
        vv.push_back(sum);
    }
    int ans = 0, lt = tmm - tt;
    sort(vv.begin(), vv.end());
    for (auto i : vv)
    {
        if (2 * i <= lt)
        {
            ans++;
            lt -= 2 * i;
        }
    }
    cout << ans << endl;
    return 0;
}