#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
int a[N], s[N], dp[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (a[i] >= 0)
            dp[i] = 1;
    }
    if (s[n] < 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (dp[j] > 0 && s[i] - s[j] >= 0)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}