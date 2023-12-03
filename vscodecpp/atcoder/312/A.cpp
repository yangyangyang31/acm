#include <bits/stdc++.h>

using namespace std;
#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define endl '\n'
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

signed main(void)
{
    IOS;
    vector<string> s;
    s.push_back("ACE");
    s.push_back("BDF");
    s.push_back("CEG");
    s.push_back("DFA");
    s.push_back("EGB");
    s.push_back("FAC");
    s.push_back("GBD");
    string a;
    cin >> a;
    for (auto i : s)
    {
        if (a == i)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}