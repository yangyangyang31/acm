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

const int N = 2e5 + 10;
int p[N], q[N], a[N], b[N];
map<int, map<int, int>> mp;

signed main(void)
{
    IOS;
    int w, h, n, maxx = 0, mx = 0, my = 0, cnt = 0;
    mp[a[mx]][b[my]] = 10 * N;
    cin >> w >> h >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> q[i];
    int A, B;
    cin >> A;
    for (int i = 1; i <= A; i++)
        cin >> a[i];
    cin >> B;
    for (int i = 1; i <= B; i++)
        cin >> b[i];
    a[A + 1] = w;
    b[B + 1] = h;
    for (int i = 1; i <= n; i++)
    {
        int x = upper_bound(a + 1, a + 1 + A, p[i]) - a;
        int y = upper_bound(b + 1, b + 1 + B, q[i]) - b;
        // cout << endl
        //<< p[i] << " " << q[i] << endl;
        // cout << x << " " << y << endl;
        // cout << a[x] << " " << b[y] << endl;
        if (mp[a[x]][b[y]] == 0)
            cnt++;
        mp[a[x]][b[y]]++;
        maxx = max(maxx, mp[a[x]][b[y]]);
        // minn = min(minn, mp[a[x]][b[y]]);
        if (mp[a[x]][b[y]] < mp[a[mx]][b[my]])
        {
            mx = x;
            my = y;
        }
    }
    // for (auto item : mp)
    // {
    //     cout << endl
    //          << item.first << " ";
    //     for (auto i : item.second)
    //         cout << i.first << " " << i.second << endl;
    // }
    if (cnt < (A + 1) * (B + 1) || n < (A + 1) * (B + 1))
        cout << 0 << " " << maxx << endl;
    else
        cout << mp[a[mx]][b[my]] << " " << maxx << endl;
    return 0;
}