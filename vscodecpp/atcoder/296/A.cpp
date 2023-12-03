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
    bool f = true;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            f = false;
            break;
        }
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main(void)
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}