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

const int mod = 1000000007;

struct Matrix
{
	int a[3][3];
	Matrix() { memset(a, 0, sizeof a); } // 构造函数，矩阵初始化全零
	Matrix operator*(const Matrix &b) const
	{
		Matrix res;
		for (int i = 1; i <= 2; ++i)
			for (int j = 1; j <= 2; ++j)
				for (int k = 1; k <= 2; ++k)
					res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		return res;
	}
} ans, base;

void init()
{ // 初始化 ans、base 矩阵
	base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
	ans.a[1][1] = ans.a[1][2] = 1;
}

Matrix quick_multi(Matrix a, int t) // 矩阵快速幂
{
	Matrix res; // 单位矩阵
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			res.a[i][j] = (i == j);
	while (t)
	{
		if (t & 1)
			res = res * a;
		t >>= 1;
		a = a * a;
	}
	return res;
}

signed main()
{
	int n;
	cin >> n;

	init();    //初始化矩阵

	Matrix m = quick_multi(base, n);
	ans = m * ans;

	cout << ans.a[1][1] % mod << endl;
}