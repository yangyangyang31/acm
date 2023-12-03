#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            continue;
        else
        {
            if (s[i] == '1' && t[i] == 'l')
                continue;
            if (t[i] == '1' && s[i] == 'l')
                continue;
            if (s[i] == '0' && t[i] == 'o')
                continue;
            if (t[i] == '0' && s[i] == 'o')
                continue;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}