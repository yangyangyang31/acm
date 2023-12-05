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
    int a[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
    int n;
    cin >> n;
    int ans = 1;
    while (n)
    {
        ans *= a[n % 10];
        n /= 10;
    }
    cout << ans << endl;
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