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

struct node
{
	int sh, gjfw, smz;
} nodes[8];

void solve()
{
	nodes[1] = {60, 3, 1200};
	nodes[2] = {55, 3, 1300};
	nodes[3] = {40, 5, 650};
	nodes[4] = {185, 6, 900};
	nodes[5] = {84, 2, 800};
	nodes[6] = {170, 0, 1350};
	nodes[7] = {60, 3, 800};
	int n, m, s, a, b, t, sumtt = 0;
	cin >> n >> m >> s >> a >> b >> t;
	vector<int> v(n + 2);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (nodes[v[i]].smz % a)
			sumtt++;
		sumtt += nodes[v[i]].smz / a;
	}
	for (int k = 1; k <= sumtt; k++)
	{
		int cnt = 0, mm = m, jnsj = 0, jzsm = nodes[v[cnt + 1]].smz; // cnt目前在的点
		for (int i = 1;; i++)
		{
			bool f = false;
			if (k == 5)
				cout << "第" << i << "秒时：" << endl;
			if (i == k)
			{
				mm = min(m, mm + a); // 到技能使用时间
				jnsj = t;
			}
			int sum = 0;				 // sum：在i时刻受到的总伤害
			for (int j = 1; j <= 6; j++) // 建筑的最大攻击范围为6
			{
				if (cnt + j > n)
					break;
				int tt = v[j + cnt];	 // 距离自己为j的点的建筑类型
				int jl = nodes[tt].gjfw; // 能攻击的范围
				if (j == 1 && tt == 6)	 // 面前第一个为投石炮
					continue;
				if (jl >= j)
					sum += nodes[tt].sh;
			}
			mm -= sum; // 减去收到伤害
			if (jnsj)  // 在技能时间内
			{
				jzsm -= s + b;
				jnsj--;
			}
			else // 不在技能时间内
				jzsm -= s;
			if (jzsm <= 0) // 面前建筑清零
			{
				cnt++;
				jzsm = nodes[v[cnt + 1]].smz; // 更新所在位置，和面前建筑生命
				if (k == 5)
				{
					cout << "远神受到" << sum << "点伤害,剩余" << mm << "生命" << endl;
					cout << "建筑受到" << (jnsj ? s + b : s) << "伤害，剩余" << 0 << "生命" << endl;
					cout << "远神将第" << cnt << "个建筑摧毁" << endl;
				}
				// 向前走所受的伤害
				if (v[cnt] != 6) // 如果消灭的不是投石炮
					sum -= nodes[cnt].sh;
				mm -= sum;
				if (v[cnt] == 7) // 消灭的是炸弹塔
					mm -= 30;

				i++;

				if (k == 5)
				{
					f = true;
					cout << "第" << i << "秒向前走,受到" << sum << "点伤害，剩余" << mm << "生命" << endl;
					cout << "建筑受到" << 0 << "伤害，剩余" << jzsm << "生命" << endl;
				}
				if (jnsj) // 行走过程也算技能时间
					jnsj--;
			}
			if (mm <= 0) // 远神血量清零
				break;
			if (cnt == n)
			{
				cout << k << " "
					 << "Yes" << endl;
				f = true;
				return;
			}

			if (!f && k == 5)
			{
				cout << "远神受到" << sum << "点伤害,剩余" << mm << "生命" << endl;
				cout << "建筑受到" << (jnsj ? s + b : s) << "伤害，剩余" << jzsm << "生命" << endl;
			}
		}
	}
	cout << "No" << endl;
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