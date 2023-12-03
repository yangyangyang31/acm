#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ll arr[64] = {1};

int main()
{
    for (int i = 1; i <= 63; i++)
        arr[i] = arr[i - 1] * 2;
    // cout << arr[63];
    ll ans = 0;
    for (int i = 0; i < 64; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}