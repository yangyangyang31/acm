#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 110;
int dp[2 * N][2 * N];

int main()
{
    int n, M, T;
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++)
    {
        int m, t;
        cin >> m >> t;
        for (int j = M; j >= m; j--)
            for (int k = T; k >= t; k--)
                dp[j][k] = max(dp[j][k], dp[j - m][k - t] + 1);
    }
    cout << dp[M][T] << endl;
    return 0;
}