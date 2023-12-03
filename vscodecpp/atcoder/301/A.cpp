#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n, a = 0, t = 0;
    char x;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            a++;
        else
            t++;
        if (a > t)
            x = 'A';
        else if (a < t)
            x = 'T';
    }
    cout << x << endl;
    return 0;
}