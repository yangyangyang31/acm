#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int st[N];
map<int, map<int, int>> mp;

int main()
{
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
            st[i + 1] = 0;
        if (s[i] == 'L')
            st[i + 1] = 1;
        if (s[i] == 'U')
            st[i + 1] = 2;
        if (s[i] == 'D')
            st[i + 1] = 3;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = st[i];
        x += dx[j], y += dy[j];
        h--;
        if (h < 0)
        {
            cout << "No" << endl;
            return 0;
        }
        if (mp[x][y] == 1 && h < k)
        {
            h = k;
            mp[x][y] = 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
