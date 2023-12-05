#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int p[N][N], a[N], b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (b[j] == a[i])
                p[i][j] = max(p[i - 1][j], p[i][j - 1] + 1);
            else
                p[i][j] = max(p[i - 1][j], p[i][j - 1]);
        }
    cout << p[n][n];
    return 0;
}