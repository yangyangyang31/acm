#include <bits/stdc++.h>
using namespace std;

int minn = 1e9 + 10;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        minn = min(minn, x);
    }
    cout << min(p, minn + q);
    return 0;
}