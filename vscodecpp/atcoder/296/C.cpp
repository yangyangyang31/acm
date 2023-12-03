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
set<int> v;

signed main(void)
{
    IOS;
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.insert(x);
    }
    for (auto item : v)
    {
        if (v.find(item + x) != v.end() || v.find(item - x) != v.end())
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}