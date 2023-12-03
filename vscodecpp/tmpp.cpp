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
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    int n = a.size(), m = b.size(), x, y;
    cin >> x >> y;
    vector<vector<int>> d(n + 1, vector<int>(m + 1));
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
