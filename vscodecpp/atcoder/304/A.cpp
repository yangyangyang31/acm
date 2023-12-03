#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, string> pis;
vector<pis> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        string s;
        cin >> s >> x;
        mp.push_back({x, s});
    }
    long long minn = 1e9 + 10, ans = 0;
    for (int i = 0; i < mp.size(); i++)
    {
        if (minn > mp[i].first)
        {
            ans = i;
            minn = mp[i].first;
        }
    }
    cout << mp[ans].second << endl;
    for (int i = ans + 1;; i++)
    {
        if (i >= mp.size())
            i = 0;
        if (i == ans)
            break;
        cout << mp[i].second << endl;
    }
    // cout << mp[ans - 1].second << endl;
    return 0;
}