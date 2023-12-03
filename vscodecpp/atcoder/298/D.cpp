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

const int mod = 998244353;
int p[600005], s[600005], l = 0, r = 1, q, ans;
signed main()
{
    IOS;

    cin >> q;
    int id, x;
    p[0] = 1, s[0] = 1, ans = 1;
    for (int i = 1; i <= 600000; i++)
        p[i] = p[i - 1] * 10 % mod;
    for (int i = 1; i <= q; i++)
    {
        cin >> id;
        if (id == 1)
        {
            cin >> x;
            s[r++] = x;
            ans = (ans * 10 + x) % mod;
        }
        else if (id == 2)
        {
            ans = ((ans - p[r - l - 1] * s[l]) % mod + mod) % mod;
            l++;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
