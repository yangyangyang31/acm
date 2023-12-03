#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<string> v;

bool is_rev(string s)
{
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        l++, r--;
        if (s[l] != s[r])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                continue;
            string s = v[i] + v[j];
            if (is_rev(s))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    cout << "No" << endl;
    return 0;
}