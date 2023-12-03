#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
typedef pair<int, int> PII;

typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
const int N = 2e5 + 5, INF = 0x3f3f3f3f, Mod = 1e9 + 7;
const double eps = 1e-6;
vector<int> ve(N);
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> ve[i];
    int s = n * (n + 1) / 2;
    if (ve[n - 1] > s)
    {
        cout << "NO\n";
        return;
    }
    int m = n - 1;
    if (ve[n - 1] != s)
        ve[n] = s, m++;
    set<int> se;
    int e1 = -1;
    for (int i = 1; i <= m; ++i)
    {
        int a = ve[i] - ve[i - 1];
        if (a <= n)
        {
            if (se.count(a) == 0)
                se.insert(a);
            else if (e1 == -1)
            {
                e1 = a;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else if (e1 == -1)
        {
            e1 = a;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    if (e1 != -1)
    {
        int ss = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (se.count(i) == 0)
                ss += i;
        }
        if (ss == e1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "YES\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // init();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}