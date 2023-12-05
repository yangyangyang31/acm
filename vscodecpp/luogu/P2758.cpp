#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int dp[N][N];

int main()
{
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int n = s.size() - 1, m = t.size() - 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (s[i] == t[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
    return 0;
}