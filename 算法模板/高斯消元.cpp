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

double eps = 1e-7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<double>> a(n + 5, vector<double>(n + 5));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) // 枚举每一列
    {
        int mx = i;
        for (int j = i + 1; j <= n; j++) // 选最大的系数
        {
            if (fabs(a[j][i]) > fabs(a[mx][i]))
                mx = j;
        }
        for (int j = 1; j <= n + 1; j++) // 最大系数移到最前
            swap(a[i][j], a[mx][j]);
        if (fabs(a[i][i]) < eps) // 最大系数为0 无解
        {
            cout << "No Solution" << endl;
            return;
        }
        for (int j = n + 1; j >= 1; j--) // 把这行的主元素系数变为1
            a[i][j] = a[i][j] / a[i][i];
        for (int j = 1; j <= n; j++) // 消去主元素所在列的其他主元素
        {
            if (j != i)
            {
                double tmp = a[j][i] / a[i][i];
                for (int k = 1; k <= n + 1; k++)
                    a[j][k] -= a[i][k] * tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(2) << a[i][n + 1] << endl;
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
