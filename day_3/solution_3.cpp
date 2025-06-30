#include <vector>

std::vector<int> solution(int n, int m, std::vector<int>& swaps) {
    std::vector<int> result;
    int soldiers[2*n];
    int methods_on_right_place = n;
    //create massive of soldiers
    for(int i = 0; i < 2*n; i++)
    {
        soldiers[i] = i;
    }
    
    int first_pos = 0;
    int second_pos = 0;
    int memory = 0;

    for(int i = 0; i < m; i++)
    {
        first_pos = std::min(swaps[2*i] - 1,swaps[2*i+1] - 1);
        second_pos = std::max(swaps[2*i] - 1,swaps[2*i+1] - 1);

        if((first_pos >= n && second_pos >= n) || (first_pos < n && second_pos < n))
        {
            std::swap(soldiers[first_pos],soldiers[second_pos]);
            result.push_back(methods_on_right_place);
            continue;
        }

        if(soldiers[second_pos] > soldiers[first_pos] && soldiers[first_pos] < n && soldiers[second_pos] >= n)
        {
            methods_on_right_place--;
        }
        else if (soldiers[first_pos] > soldiers[second_pos] && soldiers[second_pos] < n && soldiers[first_pos] >= n)
        {
            methods_on_right_place++;
        }

        std::swap(soldiers[first_pos],soldiers[second_pos]);

        result.push_back(methods_on_right_place);
    }
    
    return result;
}
