#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    bool a = false, b = false, c = false;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
            a = true;
        if (s[i] == 'B')
            b = true;
        if (s[i] == 'C')
            c = true;
        if (a && b && c)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}