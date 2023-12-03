#include <bits/stdc++.h>
using namespace std;

int a[7] = {0, 3, 1, 4, 1, 5, 9};

int main()
{
    for (int i = 1; i < 7; i++)
        a[i] = a[i] + a[i - 1];
    char x, y;
    cin >> x >> y;
    int x1 = max(x - 'A', y - 'A'), y1 = min(x - 'A', y - 'A');
    cout << a[x1] - a[y1];
    return 0;
}