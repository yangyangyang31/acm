#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
vector<int> mp[N], ans(N + 1); // ans表示删除点剩下连通块的最大值
bool st[N + 1];
int n;

int dfs(int x)
{
	st[x] = true;
	ans[x] = 1;
	int res = 1;
	for (auto i : mp[x])
	{
		if (!st[i])
		{
			st[i] = true;
			int t = dfs(i);
			res += t;
			ans[x] = max(ans[x], t);
		}
	}
	ans[x] = max(ans[x], n - res);
	return res;
}

void solve()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1);
	int a = 1;
	for (int i = 1; i <= n; i++)
	{
		if (ans[a] > ans[i])
			a = i;
		// cout << ans[i] << " ";
	}
	cout << a << endl;
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