#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, h, ans = 0;
        cin >> n >> m >> k >> h;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int dx = abs(x - h);
            if (dx % k == 0 && dx / k < m && x != h)
            {
                // cout << x << endl;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}