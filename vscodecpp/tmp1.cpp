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

void solve()
{
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x >= k)
			ans++;
	}
	cout << ans << endl;
}

signed main(void)
{
	IOS;
	int t = 1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}
