#include <bits/stdc++.h>
using namespace std;

int a[110], ans[100 * 110], cnt = 0;
;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < a[i])
        {
            for (int j = a[i - 1]; j < a[i]; j++)
                ans[++cnt] = j;
        }
        else
        {
            for (int j = a[i - 1]; j > a[i]; j--)
                ans[++cnt] = j;
        }
    }
    ans[++cnt] = a[n];
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << " ";

    return 0;
}