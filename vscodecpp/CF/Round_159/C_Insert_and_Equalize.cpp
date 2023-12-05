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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    map<pii, int> st;
    map<char, pii> d;
    d['U'] = {0, 1};
    d['D'] = {0, -1};
    d['L'] = {-1, 0};
    d['R'] = {1, 0};
    int x = 0, y = 0;
    st[{0, 0}] = 0;
    for (int i = 1; i <= n; i++)
    {
        x += d[s[i]].first, y += d[s[i]].second;
        st[{x, y}] = i;
    }
    for (int i = 1; i <= n; i++)
    {
    }
}

signed main(void)
{
    IOS;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
