#include <bits/stdc++.h>

using namespace std;
#define int long long
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
char mp[N][N];

bool check(int x, int y)
{
    rep(i, x, x + 2)
        rep(j, y, y + 2) if (mp[i][j] != '#') return false;
    rep(i, x, x + 2) if (mp[i][y + 3] == '#') return false;
    rep(i, y, y + 2) if (mp[x + 3][i] == '#') return false;

    rep(i, x + 6, x + 8)
        rep(j, y + 6, y + 8) if (mp[i][j] != '#') return false;
    rep(i, x + 6, x + 8) if (mp[i][y + 5] == '#') return false;
    rep(i, y + 6, y + 8) if (mp[x + 5][i] == '#') return false;
    return true;
}

signed main(void)
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    rep(i, 1, n)
        rep(j, 1, m)
    {
        if (mp[i][j] == '#' && check(i, j))
            cout << i << " " << j << endl;
    }
    return 0;
}