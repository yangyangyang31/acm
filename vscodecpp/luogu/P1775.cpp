// p1775  石子合并（弱化版）
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 410;
ll dp[N][N];
ll s[N]; // 前嘴和，求区间价值

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    memset(dp, 0x3f3f, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) // 一区间长度划分
    {
        for (int i = 1; i <= n - len + 1; i++) // 遍历长度为len的区间，求最小值
        {
            int j = i + len - 1;
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
        }
    }
    cout << dp[1][n] << endl; // 1到n为最小值
    return 0;
}