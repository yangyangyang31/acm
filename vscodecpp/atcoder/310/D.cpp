#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
ll dp[N][2];
string s;

int main()
{
    ll n, ans = 0;
    cin >> n >> s;
    s = " " + s;
    if (s[1] == '1')
        dp[1][1]++;
    else
        dp[1][0]++;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][1] = i - 1;
            dp[i][0] = 1;
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1];
        }
    }
    for (int i = 1; i <= n; i++)
        ans += dp[i][1];
    cout << ans << endl;
    return 0;
}