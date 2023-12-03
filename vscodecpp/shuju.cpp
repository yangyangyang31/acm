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
#define all(x) (x).begin(), (x).end() ac
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;

const int N = 1e5 + 10;
int cnt = 1, n;
pii arr[N];

void in()
{
    ofstream ofs;
    if (cnt == 1)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\1.in", ios::out);
    else if (cnt == 2)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\2.in", ios::out);
    else if (cnt == 3)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\3.in", ios::out);
    else if (cnt == 4)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\4.in", ios::out);
    else if (cnt == 5)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\5.in", ios::out);
    else if (cnt == 6)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\6.in", ios::out);
    else if (cnt == 7)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\7.in", ios::out);
    else if (cnt == 8)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\8.in", ios::out);
    else if (cnt == 9)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\9.in", ios::out);
    else if (cnt == 10)
        ofs.open("C:\\Users\\26389\\Desktop\\data\\10.in", ios::out);
    ofs << n << endl;
    for (int i = 1; i <= n; i++)
        ofs << arr[i].first << " " << arr[i].second << endl;

    ofs.close();
}

void out()
{
    ofstream fs;
    if (cnt == 1)
        fs.open("C:\\Users\\26389\\Desktop\\data\\1.out", ios::out);
    else if (cnt == 2)
        fs.open("C:\\Users\\26389\\Desktop\\data\\2.out", ios::out);
    else if (cnt == 3)
        fs.open("C:\\Users\\26389\\Desktop\\data\\3.out", ios::out);
    else if (cnt == 4)
        fs.open("C:\\Users\\26389\\Desktop\\data\\4.out", ios::out);
    else if (cnt == 5)
        fs.open("C:\\Users\\26389\\Desktop\\data\\5.out", ios::out);
    else if (cnt == 6)
        fs.open("C:\\Users\\26389\\Desktop\\data\\6.out", ios::out);
    else if (cnt == 7)
        fs.open("C:\\Users\\26389\\Desktop\\data\\7.out", ios::out);
    else if (cnt == 8)
        fs.open("C:\\Users\\26389\\Desktop\\data\\8.out", ios::out);
    else if (cnt == 9)
        fs.open("C:\\Users\\26389\\Desktop\\data\\9.out", ios::out);
    else if (cnt == 10)
        fs.open("C:\\Users\\26389\\Desktop\\data\\10.out", ios::out);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].second == 1)
            fs << "XyeeCheng" << endl;
        else if (arr[i].second == 2)
            fs << "fsjhhh" << endl;
    }
    fs.close();
}

signed main(void)
{
    srand((unsigned int)(time(0)));

    for (cnt = 1; cnt <= 10; cnt++)
    {
        n = rand() % N;
        for (int i = 1; i <= n; i++)
        {
            arr[i].first = rand() % N + 1e9 + 10;
            arr[i].second = rand() % 2 + 1;
        }
        in();
        out();
    }
    return 0;
}