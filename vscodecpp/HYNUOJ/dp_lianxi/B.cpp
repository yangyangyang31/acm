#include <iostream>
using namespace std;

const int N = 1005;
int dp[N][N], arr[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> arr[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
        }
    }
    int ant = 0;
    for (int i = 1; i <= n; i++)
        if (ant < dp[n][i])
            ant = dp[n][i];
    cout << ant;
    return 0;
}