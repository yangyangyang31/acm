#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll dp[N], arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if (x > n)
                continue;
            else
                arr[x]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0)
                continue;
            for (int j = i; j <= n; j += i)
                dp[j] += arr[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dp[i]);
            dp[i] = arr[i] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}