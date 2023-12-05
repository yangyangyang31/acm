#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 40;
ll mp[N][N], dp[N][N];
int n, m, x, y;
int dx[8] = {2, 1, -2, 1, 2, -1, -2, -1}, dy[8] = {1, 2, 1, -2, -1, 2, -1, -2};

int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0)
            mp[nx][ny] = 1;
    }
    dp[0][0] = 1;
    mp[x][y] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (mp[i][j])
                continue;
            if (i != 0)
                dp[i][j] += dp[i - 1][j];
            if (j != 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
