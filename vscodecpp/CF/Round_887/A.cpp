#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, last = -1e9, minn = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            minn = min(minn, x - last);
            last = x;
        }
        if (minn < 0)
            cout << 0 << endl;
        else if (minn == 0)
            cout << 1 << endl;
        else
            cout << minn / 2 + 1 << endl;
    }
    return 0;
}