#include <vector>

std::vector<int> solution(int n, int m, std::vector<int>& p) {
    std::vector<int> result;
    //Check if last num is -1. You can sum any nums.
    if (p.back() < n * m && p.back() != -1)
    {
        result.push_back(-1);
    }
    else
    {
        p[0] = p[0] == -1 ? m : p[0];
        result.push_back(p[0]);
        for (int i = 1; i < n; i++)
        {
            if (p[i] != -1)
            {
                if (p[i] - p[i - 1] < m)
                {
                    result.clear();
                    result.push_back(-1);
                    return result;
                }
                else
                {
                    result.push_back(p[i] - p[i - 1]);
                }
            }
            else
            {
                result.push_back(m);
                p[i] = p[i - 1] + m;
            }

        }
    }
    return result;
}