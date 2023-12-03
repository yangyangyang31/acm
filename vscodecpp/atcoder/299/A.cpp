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
    cin >> n;
    string s, tmp;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '.')
            tmp += s[i];
    }
    for (int i = 0; i < 3; i++)
    {
        if (tmp[i] == '*')
            if (i == 1)
                cout << "in" << endl;
            else
                cout << "out" << endl;
    }
    return 0;
}