#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    int l, r;
    // �������
    while (l < r)
    {
        int mid = l + r >> 1; //(l + r) / 2
        if (check(mid))
            r = mid; // check()�ж�mid�Ƿ���������
        else
            l = mid + 1;
    }
    // ���Ҳ���
    while (l < r)
    {
        int mid = l + r + 1 >> 1; //(l + r + 1) / 2
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    // �������
    for (int i = 0; i <= 100; i++) // ��Ҫһ�����ȱ�֤
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid; // ��r = mid;
        else
            r = mid; // ��l = mid;
    }
}