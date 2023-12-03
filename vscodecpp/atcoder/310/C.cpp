#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int son[N][26], cnt[N], idx;

void insert(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (query(s) == 0)
        {
            reverse(s.begin(), s.end());
            if (query(s) == 0)
            {
                ans++;
                insert(s);
            }
        }
    }
    cout << ans << endl;
    return 0;
}