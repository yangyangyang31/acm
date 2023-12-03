#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int arr[N], dp[N];
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        sort(arr + 1, arr + n + 1);
        int maxx = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            if (arr[i] - arr[i - 1] <= k)
            {
                dp[i] = dp[i - 1] + 1;
                if (dp[i] > maxx)
                    maxx = dp[i];
            }
        }
        cout << n - maxx << endl;
    }
    return 0;
}