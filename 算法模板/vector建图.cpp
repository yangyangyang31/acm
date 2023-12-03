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

const int N=1e5+10;

struct edge
{
	int to, v;
};

vector<edge> mp[N + 1];


void solve()
{
	int n, m;
	cin >> n >> m;
	map<int, int> st;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		st[x] = 1;
	}
	edge tmp;
	tmp.v = 1;
	for (int i = 1; i < n; i++)
	{
		int a;
		cin >> a >> tmp.to >> tmp.v;
		mp[a].push_back(tmp);
	}
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