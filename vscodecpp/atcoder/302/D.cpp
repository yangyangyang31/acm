#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main(void)
{
    int n, m;
    long long d, x, y;

    cin >> n >> m >> d;
    vector<long long> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (true)
    {
        if ((n == 0) || (m == 0))
        {
            cout << -1 << endl;
            return 0;
        }
        x = a.back(), y = b.back();
        if (abs(x - y) <= d)
        {
            cout << (x + y) << endl;
            return 0;
        }
        if (x > y)
            a.pop_back(), n--;
        else
            b.pop_back(), m--;
    }

    return 0;
}
