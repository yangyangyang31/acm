#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[510];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            dp[j] += dp[j - i];
    cout << dp[n] - 1 << endl;
    return 0;
}