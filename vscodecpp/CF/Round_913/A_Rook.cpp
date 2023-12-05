#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    char a;
    int b;
    cin >> a >> b;
    for (int i = 1; i <= 8; i++)
        if (b != i)
            cout << a << i << endl;
    for (int i = 0; i < 8; i++)
        if ((char)('a' + i) != a)
            cout << (char)('a' + i) << b << endl;
}

signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}