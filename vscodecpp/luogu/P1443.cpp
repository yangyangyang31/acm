#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 410;
int n, m, x, y;
int mp[N][N];
int dx[8] = {2, 1, -2, 1, 2, -1, -2, -1}, dy[8] = {1, 2, 1, -2, -1, 2, -1, -2};

void bfs()
{
    mp[x][y] = 0;
    queue<pii> q;
    q.push({x, y});
    while (q.size())
    {
        pii t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] != -1)
                continue;
            else
            {
                mp[nx][ny] = mp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    memset(mp, -1, sizeof mp);
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mp[i][j] << " ";
        cout << endl;
    }
    return 0;
}