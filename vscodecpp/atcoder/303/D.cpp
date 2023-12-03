#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 1e18 + 10;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    vector<vector<long long>> dp(s.size() + 1, vector<long long>(2, INF));
    dp[0][0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int cur;
        if (s[i] == 'a')
            cur = 0;
        else
            cur = 1;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ll v = dp[i][j];
                if (j != k)
                    v += c;
                if (k == cur)
                    v += a;
                else
                    v += b;
                dp[i + 1][k] = min(dp[i + 1][k], v);
            }
        }
    }
    cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;
    return 0;
}