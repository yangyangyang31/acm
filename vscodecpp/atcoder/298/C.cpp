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

const int N = 200010;
const int M = 200010;
vector<vector<int>> box(N, vector<int>());
vector<vector<int>> card(M, vector<int>());

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ans;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, j;
            cin >> i >> j;
            card[i].push_back(j);
            box[j].push_back(i);
        }
        else if (t == 2)
        {
            int i;
            cin >> i;
            sort(box[i].begin(), box[i].end());
            for (int j = 0; j < box[i].size(); j++)
            {
                cout << box[i][j] << "\n "[j + 1 != box[i].size()];
            }
        }
        else
        {
            int i;
            cin >> i;
            sort(card[i].begin(), card[i].end());
            card[i].erase(unique(card[i].begin(), card[i].end()), card[i].end());
            for (int j = 0; j < card[i].size(); j++)
            {
                cout << card[i][j] << "\n "[j + 1 != card[i].size()];
            }
        }
    }
}
