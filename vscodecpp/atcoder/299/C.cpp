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

signed main(void)
{
    IOS;
    int n;
    string s;
    int ans = 0, sum = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            sum++;
        else if (s[i] == '-')
        {
            ans = max(ans, sum);
            sum = 0;
        }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'o')
            sum++;
        else if (s[i] == '-')
        {
            ans = max(ans, sum);
            sum = 0;
        }
    }
    if (ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}