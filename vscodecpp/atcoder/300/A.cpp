#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == a + b)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}