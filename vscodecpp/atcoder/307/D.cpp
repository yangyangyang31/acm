#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> v;

void merge(vector<pii> &segs) // 区间合并
{
    vector<pii> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);

    if (st != -2e9)
        res.push_back({st, ed});

    segs = res;
}
int main()
{
    stack<int> q;
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            q.push(i);
        if (q.size() && s[i] == ')')
        {
            v.push_back({q.top(), i});
            q.pop();
        }
    }
    merge(v);
    for (auto item : v)
    {
        int x = item.first, y = item.second;
        for (int i = x; i <= y; i++)
            s[i] = '0';
    }
    string ans;
    for (int i = 0; i < n; i++)
        if (s[i] != '0')
            ans += s[i];
    cout << ans << endl;
    return 0;
}