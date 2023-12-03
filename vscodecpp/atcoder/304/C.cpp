#include <bits/stdc++.h>
using namespace std;
int n, d, fa[2010], x[2010], y[2010];
int F(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = F(fa[x]);
}
int p2(int x)
{
    return x * x;
}
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        fa[i] = i, cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (p2(x[i] - x[j]) + p2(y[i] - y[j]) <= d * d)
                fa[F(i)] = F(j);
    for (int i = 1; i <= n; i++)
        puts((F(1) == F(i)) ? "Yes" : "No");
    return 0;
}