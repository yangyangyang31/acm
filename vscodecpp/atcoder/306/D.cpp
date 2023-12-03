#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[300005], dp1, dp2;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
            dp2 = max(dp2, dp1 + y);
        else
            dp1 = max(dp1 + max(y, 0ll), dp2 + y);
    }
    cout << max(dp1, dp2) << endl;
    return 0;
}