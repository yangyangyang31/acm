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

signed main(void)
{
    IOS;
    int n;
    cin >> n;
    bool f = true;
    int x, maxx;
    cin >> x;
    maxx = x;
    for (int i = 1; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == x)
            f = false;
        maxx = max(maxx, t);
    }
    if (maxx == x)
    {
        if (f)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    else
        cout << maxx - x + 1 << endl;

    return 0;
}