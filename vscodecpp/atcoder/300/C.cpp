#include <bits/stdc++.h>
using namespace std;

const int N = 150;
char mp[N][N];
int arr[N];
int n, m;

int get_num(int x, int y)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[x + i][y + i] == '#' && mp[x + i][y - i] == '#' && mp[x - i][y + i] == '#' && mp[x - i][y - i] == '#')
        {
            ans++;
            mp[x + i][y + i] = mp[x - i][y - i] = mp[x + i][y - i] = mp[x - i][y + i] = '.';
        }
        // else if (mp[x + i][y + i] != '#' && mp[x - i][y - i] != '#' && mp[x - i][y + i] != '#' && mp[x + i][y - i] != '#')
        // return ans;
        else
            return ans;
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
            if (mp[i][j] == '#')
                arr[get_num(i, j)]++;
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    return 0;
}