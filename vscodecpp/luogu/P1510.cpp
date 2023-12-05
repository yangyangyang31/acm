#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 10;
int k[N], m[N], dp[N];

int main()
{
    int v, n, c;
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> k[i] >> m[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= m[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - m[i]] + k[i]);
        }
    }
    for (int i = 0; i <= c; i++)
        if (dp[i] >= v)
        {
            cout << c - i << endl;
            return 0;
        }
    cout << "Impossible" << endl;
    return 0;
}
