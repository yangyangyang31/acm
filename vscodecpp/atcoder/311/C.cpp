#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], idx, step[N], pre[N];
bool st[N];
int ans = 0;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int d)
{
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            step[j] = d + 1;
            pre[u] = j;
            dfs(j, d + 1);
        }
        else
        {
            ans = d - step[j] + 1;
            vector<int> v;
            for (int i = 1; i <= ans; i++)
            {
                v.push_back(j);
                j = pre[j];
            }
            cout << ans << endl;
            for (auto item : v)
                cout << item << " ";
            return;
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(i, x);
    }
    dfs(1, 0);
    return 0;
}