#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++)
    {
        std::cin >> S[i];
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            for (auto dx : {-1, 0, 1})
            {
                for (auto dy : {-1, 0, 1})
                {
                    if (dx || dy)
                    {
                        bool ok = true;
                        for (int k = 0; k < 5; k++)
                        {
                            int x = i + dx * k;
                            int y = j + dy * k;
                            if (!(0 <= x && x < H && 0 <= y && y < W && S[x][y] == "snuke"[k]))
                            {
                                ok = false;
                            }
                        }
                        if (ok)
                        {
                            for (int k = 0; k < 5; k++)
                            {
                                int x = i + dx * k;
                                int y = j + dy * k;
                                std::cout << x + 1 << " " << y + 1 << "\n";
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}