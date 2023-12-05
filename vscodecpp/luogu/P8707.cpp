#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 50;
int dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
                continue;
            else
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}