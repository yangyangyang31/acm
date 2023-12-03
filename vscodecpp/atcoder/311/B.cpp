#include <bits/stdc++.h>
using namespace std;

char mp[110][110];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    int sum = 0, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (mp[1][i] == 'o')
        {
            bool f = true;
            for (int j = 1; j <= n; j++)
                if (mp[j][i] == 'x')
                    f = false;
            if (f)
                sum++;
            else
                sum = 0;
            ans = max(sum, ans);
        }
        else
            sum = 0;
    }
    cout << ans << endl;
    return 0;
}