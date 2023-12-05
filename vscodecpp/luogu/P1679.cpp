#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100000;
vector<int> v;
int n, st[N];

void que()
{
    for (int i = 1; i * i * i * i < N; i++)
        v.push_back(i * i * i * i);
}

void bfs()
{
    queue<int> q;
    for (auto item : v)
    {
        if (item < n)
        {
            q.push(item);
            st[item] = 1;
        }
        else
            break;
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        if (t == n)
        {
            cout << st[t] << endl;
            return;
        }

        for (auto item : v)
        {
            if (t + item <= n && st[t + item] == 0)
            {
                st[t + item] = st[t] + 1;
                q.push(t + item);
            }
        }
    }
}
int main()
{
    que();
    cin >> n;
    bfs();
    return 0;
}