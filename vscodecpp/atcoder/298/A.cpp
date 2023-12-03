#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

signed main(void)
{
    IOS;
    int n;
    bool f1 = false, f2 = true;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            f1 = true;
        if (s[i] == 'x')
            f2 = false;
    }
    if (f1 && f2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}