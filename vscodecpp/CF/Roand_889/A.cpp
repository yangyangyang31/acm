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

const int N = 1e5 + 10;
int a[N];

void solve()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == i)
            sum++;
    }
    cout << (sum + 1) / 2 << endl;
}

signed main(void)
{
    IOS;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}