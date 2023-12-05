#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ans = 1e9 + 10;
vector<pii> v;
bool st[20];
int n, sum, a = 1, b;

void dfs(int u)
{
    // st[u] = true;
    for (int i = u; i < n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            a *= v[i].first, b += v[i].second;
            ans = min(ans, abs(b - a));
            dfs(u + 1);
            st[i] = false;
            a /= v[i].first, b -= v[i].second;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}