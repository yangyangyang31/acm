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
int arr[N];
struct node
{
	ll val;
	int l, r,lazy;
}t[4*N];

void bulid(int u, int l, int r)        //建树
{
	t[u].l = l;
	t[u].r = r;
	if (l == r)
	{
		t[u].val = arr[l];
		return;
	}
	int mid = l + r >> 1;
	bulid(u << 1, l, mid);
	bulid(u << 1 | 1, mid + 1, r);
	t[u].val = t[u << 1].val + t[u << 1 | 1].val;
}

void modify_one(int u, int x, int y)  //单点修改
{
	if (t[u].l == t[u].r)
	{
		t[u].val = y;
		return;
	}
	int mid = t[u].l + t[u].r >> 1;
	if (x <= mid) modify_one(u << 1, x, y);
	else modify_one(u << 1 | 1, x, y);
	t[u].val = t[u << 1].val + t[u << 1 | 1].val;
}

void pushdowm(int u)           //上往下
{
	t[u << 1].val += t[u].lazy * (t[u << 1].r - t[u << 1].l + 1);
	t[u << 1 | 1].val += t[u].lazy * (t[u << 1 | 1].r - t[u << 1 | 1].l + 1);
	//更新儿子数据

	t[u << 1].lazy += t[u].lazy;
	t[u << 1 | 1].lazy += t[u].lazy;
	//父亲的lazy下传给子

	t[u].lazy = 0;
}

void pushup(int u)                    //下往上
{
	t[u].val = t[u << 1].val + t[u << 1 | 1].val;
}

void modify_lr(int u, int l, int r, int x)       //区间修改
{
	if (l <= t[u].l && r >= t[u].r)
	{
		t[u].lazy += x;
		t[u].val += x * (t[u].r - t[u].l + 1);
		return;
	}

	int mid = t[u].l + t[u].r >> 1;

	pushdowm(u);
	if (l <= mid) modify_lr(u << 1, l, r, x);
	if (mid < r)modify_lr(u << 1 | 1, l, r, x);

	pushup(u);
}

ll query(int u, int l, int r)             //查询
{
	if (t[u].l > r || t[u].r < l)	return 0;
	if (t[u].l >= l && t[u].r <= r)	return t[u].val;

	pushdowm(u);

	return query(u << 1, l, r) + query(u << 1 | 1, l, r);
}

signed main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	bulid(1, 1, n);
	while (q--)
	{
		int o, l, r, x;
		cin >> o >> l >> r;
		if (o == 1)
		{
			cin >> x;
			pushdowm(1);
			modify_lr(1, l, r, x);
		}
		else	
			cout << query(1, l, r)<<endl;
	}
	return 0;
}