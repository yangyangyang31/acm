#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, p, l, t;
    cin >> n >> p >> l >> t;
    int k = 0;
    if (n % 7 != 0)
        k++;
    k += n / 7;
    int k1, w1, k2, w2;
    if (k % 2 == 0)
    {
        w1 = 2 * t + l;
        k1 = k / 2;
        w2 = t + l;
        k2 = 0;
    }
    else
    {
        w1 = 2 * t + l;
        k1 = k / 2;
        w2 = t + l;
        k2 = 1;
    }
    if (w1 * k1 >= p)
    {
        int ans = p / w1;
        if (p % w1 != 0)
            ans++;
        cout << n - ans << endl;
    }
    else if (w1 * k1 + w2 * k2 >= p)
    {
        cout << n - k1 - k2 << endl;
    }
    else
    {
        p -= w1 * k1 + w2 * k2;
        int ans = k1 + k2;
        if (p % l != 0)
            ans++;
        ans += p / l;
        cout << n - ans << endl;
    }
}

signed main(void)
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
