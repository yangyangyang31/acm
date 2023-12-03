#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        vector<int> v;
        int n, sum = 0, ans = 0;
        cin >> n >> s;
        v.push_back(0);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                sum++;
            else
            {
                ans = max(sum, ans);
                sum = 0;
            }
            // cout << sum << " ";
        }
        ans = max(sum, ans);
        cout << ans + 2 << endl;
        // v.clear();
    }
    return 0;
}
