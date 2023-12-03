#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
int main()
{
    scanf("%d", &n);
    int l = 1, r = n, mid;
    while (r - l + 1 > 2)
    {
        mid = (l + r) / 2;
        printf("? %d\n", mid);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        if (x == 0)
            l = mid;
        else
            r = mid;
    }
    printf("! %d\n", l);
    fflush(stdout);
    return 0;
}