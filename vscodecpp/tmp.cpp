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
    vector<int> v(n + 1);
    map<int, int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        st[v[i]]++;
    }
    sort(v.begin(), v.end());
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + v[i];
    int ans = 0, l = 0, cnt = n;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] - s[l] == v[cnt])
        {
            ans += s[i] - s[l];
            l = i;
            cnt--;
        }
        if (s[i] - s[l] > v[cnt])
        {
            ans += s[i] - s[l] + v[cnt] - (s[i] - s[l]);
            l = i - 1;
            cnt--;
        }
    }
    cout << ans << endl;
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
