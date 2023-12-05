#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> st(n);
    vector<int> tmp1, tmp2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            if (tmp1.size() == 0)
                continue;
            else
            {
                st[tmp1.back()] = true;
                tmp1.pop_back();
            }
            continue;
        }
        if (s[i] == 'b')
        {
            if (tmp2.size() == 0)
                continue;
            else
            {
                st[tmp2.back()] = true;
                tmp2.pop_back();
            }
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
            tmp1.push_back(i);
        if (s[i] >= 'a' && s[i] <= 'z')
            tmp2.push_back(i);
    }
    for (int i = 0; i < n; i++)
        if (!st[i] && s[i] != 'B' && s[i] != 'b')
            cout << s[i];
    cout << endl;
}

signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}