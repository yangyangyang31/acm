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

const int INF = 0X3f3f3f3f;
const int N = 2010;
int n, m;
int d[N][N];
int e[N], ne[N], h[N], dpath[N], idx;
bool st[N];
// 算法结束后，d[a][b]表示a到b的最短距离

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int x, int d)
{
    queue<int> q;
    q.push(x);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
        }
    }
}

signed main(void)
{
    IOS;
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int p, d;
        cin >> p >> d;
        bfs(p, d);
    }
    return 0;
}