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

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = (a + 1) / 2;
    if (x > b + c)
        cout << 2 * (b + c) + 1 << endl;
    else
        cout << 2 * x + 1 << endl;
}

signed main(void)
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}