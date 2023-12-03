#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> v;

bool check(pll a, pll b)
{
    ll dx = a.first - b.first, dy = a.second - b.second;
    if (dx == 0 || dy == 0 || dx == dy || dx == -dy)
    {
        // cout << a.first << " " << a.second << endl;
        // cout << b.first << " " << b.second << endl;
        return true;
    }
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        ll a, b;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &a, &b);
            v.push_back({a, b});
        }
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
                if (check(v[i], v[j]))
                    ans++;
        }
        cout << 2 * ans << endl;
        v.clear();
    }

    return 0;
}