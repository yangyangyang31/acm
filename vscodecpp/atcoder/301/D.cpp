#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100] = {1};
vector<ll> v, s;
ll dp[100];
bool st[100];

int main()
{
    string s;
    ll t, ans = 0;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    ll n = s.size() - 1;
    for (ll i = 1; i <= n; i++)
        a[i] = a[i - 1] * 2;
    for (ll i = 0; i <= n; i++)
    {
        if (s[i] == '1')
            ans += a[i];
        else if (s[i] == '?')
            v.push_back(a[i]);
    }
    if (ans > t)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (ans + v[i] <= t)
            ans += v[i];
    }

    cout << ans << endl;
    return 0;
}