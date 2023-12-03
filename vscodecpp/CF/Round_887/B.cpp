#include <bits/stdc++.h>
using namespace std;

const int N = 100;

struct node
{
    int x, y;
} arr[N];

int main()
{
    int t;
    cin >> t;
    arr[1].x = arr[2].y = 1;
    arr[1].y = arr[2].x = 0;
    for (int i = 3; i <= N; i++)
    {
        arr[i].x = arr[i - 1].x + arr[i - 2].x;
        arr[i].y = arr[i - 1].y + arr[i - 2].y;
    }
    while (t--)
    {
        int n, k, ans = 0;
        cin >> n >> k;
        if (n + 10 < k)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i <= n; i++)
        {
            int x = arr[k].x * i;
            if (x > n)
                break;
            if ((n - x) % arr[k].y)
                continue;
            int y = (n - x) / arr[k].y;
            if (y < i)
                break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}