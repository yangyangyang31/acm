#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 2e5 + 1;
struct node
{
    int a, b, w;
} mp[M];                                       // 用最简单且最省空间的结构体数组存边
bool cmp(node a, node b) { return a.w < b.w; } // 从小到大排序
int p[N];                                      // 并查集
int find(int x)
{ // 查询并查集，返回x的根
    if (x != p[x])
        p[x] = find(p[x]); // 路径压缩
    return p[x];
}
int n, m; // n个点，m条边
void kruskal()
{
    sort(mp + 1, mp + m + 1, cmp); // 对边做排序
    for (int i = 1; i <= n; i++)
        p[i] = i;         // 并查集初始化
    int ans = 0, cnt = 0; // cnt: 已经加入MST的边数
    for (int i = 1; i <= m; i++)
    { // 贪心：逐一加入每条边
        if (cnt == n - 1)
            break;              // 小优化：不要也行
        int e1 = find(mp[i].a); // 边的前端点a属于哪个集？
        int e2 = find(mp[i].b); // 边的后端点b属于哪个集？
        if (e1 == e2)
            continue; // 属于同一个集：产生了圈，丢弃
        else
        {                   // 不属于同一个集
            ans += mp[i].w; // 计算MST
            p[e1] = e2;     // 合并
            cnt++;          // 统计MST中的边数
        }
    }
    if (cnt == n - 1)
        cout << ans; // n-1条边
    else
        cout << "orz"; // 图不是连通的
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> mp[i].a >> mp[i].b >> mp[i].w;
    kruskal();
    return 0;
}