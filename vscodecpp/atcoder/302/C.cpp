#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n, m;

bool check()
{
    for (int i = 1; i <= n - 1; i++)
    {
        int d = 0;
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != v[i - 1][j])
                d++;
            if (d > 1)
                return false;
        }
        if (d == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    do
    {
        if (check())
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "No" << endl;
    return 0;
}