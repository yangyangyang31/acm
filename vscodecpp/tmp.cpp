#include <iostream>
using namespace std;
#include <iomanip>
const int N = 15;
int n, r;
int arr[N];
bool st[N];
void dfs(int u, int x)
{
    if (u == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << setw(3) << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = x; i <= n; i++)
        {

            arr[u] = i;
            dfs(u + 1, x + 1);
        }
    }
}
int main()
{
    cin >> n >> r;
    dfs(0, 0);
}