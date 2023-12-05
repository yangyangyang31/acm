#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0, mn = inf;
    int ans = 0;
    if (n % 2 == 1)
        ans++;
    map<char, int> st;
    for (auto item : s)
        st[item]++;
    for (auto item : st)
    {
        int tmp = item.second;
        mx = max(mx, tmp);
        mn = min(mn, tmp);
    }
    cout << max(ans, mx - (n - mx)) << endl;
}

signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}