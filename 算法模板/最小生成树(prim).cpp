#include <bits/stdc++.h>
using namespace std;

const int N = 5005, M = 2e5 + 1;
struct edge
{ // 记录边
    int to, w;
    edge(int a, int b) { to = a, w = b; } // 赋值
};
vector<edge> G[M];
struct node
{
    int id, dis;                            // id:点；dis：边
    node(int a, int b) { id = a, dis = b; } // 赋值
    bool operator<(const node &u) const { return dis > u.dis; }
};
int n, m;
bool done[N]; // done[i]=ture: 表示点i已经在MST中

void prim()
{              // 对比dijkstra: 求s到其他所有点的最短路
    int s = 1; // 从任意点开始，例如从1开始
    for (int i = 1; i <= N; i++)
        done[i] = false; // 初始化
    priority_queue<node> q;
    q.push(node(s, 0)); // 从s点开始处理队列
    int ans = 0, cnt = 0;
    while (!q.empty())
    {
        node u = q.top();
        q.pop(); // pop出距集合U最近的点u
        if (done[u.id])
            continue;      // 丢弃已经在MST中的点，有判圈的作用
        done[u.id] = true; // 标记
        ans += u.dis;
        cnt++; // 统计点数
        for (int i = 0; i < G[u.id].size(); i++)
        {                        // 检查点u的所有邻居
            edge y = G[u.id][i]; // 一个邻居y
            if (done[y.to])
                continue;            // 丢弃已经在MST中的点
            q.push(node(y.to, y.w)); // 扩展新的邻居，放进优先队列
        }
    }
    if (cnt == n)
        cout << ans; // cnt=n个点。注意在kruskal代码中cnt是边数
    else
        cout << "orz";
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(edge(b, w));
        G[b].push_back(edge(a, w)); // 双向边
    }
    prim();
    return 0;
}