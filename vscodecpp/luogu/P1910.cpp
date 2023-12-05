#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 110;
int dp[10 * N][10 * N];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        int v, b, w;
        cin >> v >> w >> b;
        for (int j = m; j >= w; j--)
            for (int k = t; k >= b; k--)
                dp[j][k] = max(dp[j][k], dp[j - w][k - b] + v);
    }
    cout << dp[m][t] << endl;
    return 0;
}