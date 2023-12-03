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

const int N = 10;
char mp[N][N];

signed main(void)
{
    IOS;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> mp[i][j];
        }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            if (mp[i][j] == '*')
                printf("%c%lld\n", 'a' + j - 1, 8 - i + 1);
        }
    return 0;
}