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
    int n;
    cin >> n;
    vector<char> v(n + 1);
    map<char, int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        st[v[i]]++;
    }
    if (st['0'] == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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
