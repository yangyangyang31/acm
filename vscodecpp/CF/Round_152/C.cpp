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

signed main(void)
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        vector<int> pre(n, -1), nxt(n, n); // pre记录在i之前的一个0出现的位置  nxt记录在i之后第一个1出现的位置
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                pre[i] = pre[i - 1];
            if (str[i] == '0')
                pre[i] = i;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1)
                nxt[i] = nxt[i + 1];
            if (str[i] == '1')
                nxt[i] = i;
        }
        set<pair<int, int>> s;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if (nxt[l] > pre[r]) // 区间内1都在0后面，无需排序
            {
                s.insert({-1, -1});
            }
            else // 离散化,找到的一个1和最后一个0的位置，区间相同就是一种
            {
                s.insert({nxt[l], pre[r]});
            }
        }
        cout << s.size() << '\n';
    }
    return 0;
}