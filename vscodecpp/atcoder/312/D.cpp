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

int mod = 998244353;

int quick_mul(int x, int y, int mod)
{
    int ans = 0;
    while (y != 0)
    {
        if (y & 1 == 1)
            ans += x, ans %= mod;
        x = x + x, x %= mod;
        y >>= 1;
    }
    return ans;
}

int quick_pow(int x, int y, int mod)
{
    int sum = 1;
    while (y != 0)
    {
        if (y & 1 == 1)
            sum = quick_mul(sum, x, mod), sum %= mod;
        x = quick_mul(x, x, mod), x %= mod;
        y = y >> 1;
    }
    return sum;
}

signed main(void)
{
    IOS;
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            ans++;
    cout << quick_pow(2, ans / 2 - 1, mod) << endl;
    return 0;
}
