#include <bits/stdc++.h>
using namespace std;

int sts[27], stt[27];

int main()
{
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '@')
            sts[s[i] - 'a' + 1]++;
        else
            sts[0]++;
        if (t[i] != '@')
            stt[t[i] - 'a' + 1]++;
        else
            stt[0]++;
    }
    int ans = 0, sum = 0;
    for (int i = 1; i < 27; i++)
    {
        if (i == 1 || i == ('t' - 'a' + 1) || i == 3 || i == ('o' - 'a' + 1) || i == 4 || i == 5 || i == ('r' - 'a' + 1))
            ans += abs(sts[i] - stt[i]);
        else
            sum += abs(sts[i] - stt[i]);
    }
    if (ans > sts[0] + stt[0] || sum != 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}