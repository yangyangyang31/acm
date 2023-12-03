#include <bits/stdc++.h>
using namespace std;

const int N = 510;
char mp[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int ans = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (mp[nx][ny] == '#')
                    ans++;
            }
            if (mp[i][j] == '.' && ans > 1)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    return 0;
}