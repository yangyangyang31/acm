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

const int N = 100;
int arr[N];

signed main(void)
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0 && ans == 0)
            ans = i;
        else if (arr[i] == 0 && ans != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}