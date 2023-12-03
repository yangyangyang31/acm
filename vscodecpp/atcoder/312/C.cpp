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

const int N = 2e5 + 10;
vector<int> a, b;

signed main(void)
{
    IOS;
    int n, m;
    cin >> n >> m;
    rep(i, 1, n)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    rep(i, 1, m)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a[0] > b[m - 1])
    {
        cout << b[m - 1] + 1 << endl;
        return 0;
    }
    rep(i, 0, n - 1)
    {
        int t = a[i];
        if (a[i + 1] == a[i])
            continue;
        int l = upper_bound(b.begin(), b.end(), t) - b.begin();
        if (b[l] != t)
        {
            if (i >= m - l - 1)
            {
                cout << t << endl;
                return 0;
            }
        }
        else
        {
            if (i >= m - l)
            {
                cout << t << endl;
                return 0;
            }
        }
    }
    return 0;
}