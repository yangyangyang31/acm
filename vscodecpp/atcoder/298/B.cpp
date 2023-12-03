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
int a[N][N], b[N][N];
bool f = false;
int n;

bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1 && a[i][j] != b[i][j])
                return false;
    return true;
}

void change()
{
    int tmp[N][N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = a[n + 1 - j][i];

    // cout << endl
    // << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = tmp[i][j];
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
}

signed main(void)
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    if (check())
    {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 1; i <= 10; i++)
    {
        change();
        if (check())
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}