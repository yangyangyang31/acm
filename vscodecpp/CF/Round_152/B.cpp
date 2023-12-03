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

bool cmp(pii a, pii b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<pii> v;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % k == 0)
            v.push_back({k, i});
        else
            v.push_back({x % k, i});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto item : v)
    {
        cout << item.second << " ";
    }
    cout << endl;
}

signed main(void)
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}