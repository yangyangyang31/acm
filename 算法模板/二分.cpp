#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    int l, r;
    // 向左查找
    while (l < r)
    {
        int mid = l + r >> 1; //(l + r) / 2
        if (check(mid))
            r = mid; // check()判断mid是否满足性质
        else
            l = mid + 1;
    }
    // 向右查找
    while (l < r)
    {
        int mid = l + r + 1 >> 1; //(l + r + 1) / 2
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    // 浮点二分
    for (int i = 0; i <= 100; i++) // 需要一个精度保证
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid; // 或r = mid;
        else
            r = mid; // 或l = mid;
    }
}