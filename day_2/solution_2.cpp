#include <vector>
#include <algorithm>

int solution(int n, std::vector<int>& a) {
    //Sorting vector
    std::sort(begin(a),end(a));
    int max_useful_nums = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int local_max_useful_nums = 0;
        int local_max_num = a[i] + n - 1;
        for(int j = i; j < a.size(); j++)
        {
            if(a[j] <= local_max_num)
            {
                local_max_useful_nums++;
            }
            else
            {
                break;
            }
        }
        if(local_max_useful_nums > max_useful_nums)
        {
            max_useful_nums = local_max_useful_nums;
        }
    }
    return n-max_useful_nums;

}
