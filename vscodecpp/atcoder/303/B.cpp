#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int st[N][N], arr[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[j];
            st[arr[j]][arr[j - 1]] = 1;
            st[arr[j - 1]][arr[j]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (st[i][j] == 0)
            {
                // cout << i << " " << j << endl;
                ans++;
            }
        }
    cout << ans << endl;
    return 0;
}