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

void solve()
{
    auto print = []
    {
        cout << "hello world" << endl;
    };
    print();
    auto f = [&](auto self, int n) -> int
    {
        if (n == 1)
            return 1;
        else
            return self(self, n - 1) + n;
    };
    cout << f(f, 5) << endl
         << endl;

    auto add = [](int a, int b)
    {
        return a + b;
    };
    cout << add(1, 3) << endl
         << endl;
    ;

    auto cmp = [](int a, int b)
    {
        return a < b;
    };
    function<int(int, int)> fcmp = cmp;

    priority_queue<int, vector<int>, decltype(fcmp)>
        pq(fcmp);
    pq.emplace(2);
    pq.emplace(1);
    pq.emplace(3);
    pq.emplace(4);
    pq.emplace(5);
    while (pq.size())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl
         << endl;

    auto ccmp = [](pii a, pii b)
    {
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(ccmp)> pqq;

    pqq.emplace(2, 4);
    pqq.emplace(1, 5);
    pqq.emplace(3, 3);
    pqq.emplace(4, 2);
    pqq.emplace(5, 1);
    while (pqq.size())
    {
        cout << pqq.top().first << " " << pqq.top().second << endl;
        pqq.pop();
    }
    cout << endl;
}

signed main(void)
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}