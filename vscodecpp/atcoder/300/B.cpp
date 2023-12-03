#include <bits/stdc++.h>
using namespace std;

const int N = 50;
char a[N][N], b[N][N];
int n, m;

bool is_ok(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[x][y] != b[i][j])
                return false;
            y++;
            if (y > m)
                y = 1;
        }
        x++;
        if (x > n)
            x = 1;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (is_ok(i, j))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    cout << "No" << endl;
    return 0;
}