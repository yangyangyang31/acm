#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N], x, y, s[N], arr[N];

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0)
            {
                a[++x] = tmp;
                s[i] = 2;
            }
            else
            {
                b[++y] = tmp;
                s[i] = 1;
            }
        }
        sort(a + 1, a + 1 + x);
        sort(b + 1, b + 1 + y);
        x = 1, y = 1;
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 1)
                arr[i] = b[x++];
            else
                arr[i] = a[y++];
            if (arr[i] < arr[i - 1])
            {
                f = false;
                cout << "NO\n";
                break;
            }
        }
        if (f)
            cout << "YES\n";
        x = y = 0;
    }
    return 0;
}