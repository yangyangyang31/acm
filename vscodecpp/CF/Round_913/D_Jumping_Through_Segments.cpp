#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
int a[N], b[N];
int n;

bool check(int x)
{
    int dx = 0, dy = 0;
    if (x < a[0])
        return false;
    else
    {
        dx = a[0];
        dy = min(b[0], x);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= dx && b[i] <= dy)
        {
            dx = a[i], dy = b[i];
            continue;
        }
        if (a[i] < dx && b[i] > dy)
        {
            dx = max(a[i], dx - x);
            dy = min(b[i], dy + x);
            continue;
        }
        if (b[i] <= dy)
        {
            if (dx - x <= a[i])
                dx = a[i], dy = b[i];
            else if (dx - x > a[i] && dx - x <= b[i])
            {
                dy = b[i];
                dx = max(a[i], dx - x);
            }
            else
                return false;
            continue;
        }
        if (a[i] >= dx)
        {
            if (dy + x >= b[i])
                dx = a[i], dy = b[i];
            else if (dy + x < b[i] && dy + x >= a[i])
            {
                dx = a[i];
                dy = min(b[i], dy + x);
            }
            else
                return false;
            continue;
        }
    }
    return true;
};

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int l = 0, r = 1e18;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
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