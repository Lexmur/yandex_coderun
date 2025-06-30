#include <vector>
#include <algorithm>

int left_side(int zero_position, std::vector<int>& a, int n)
{
    for(int i = zero_position - 1; i > 0; i--)
    { //Numbers to the left of zero shoud be negative and decrease
        if(a[i] > 0) a[i] = -a[i];
        int next_elem = a[i-1] > 0 ? -a[i-1] : a[i-1];
        if(a[i] < next_elem)
        {
            return 1;
        }
    }
    a[0] = a[0] > 0? -a[0] : a[0];
    return 0;
}

int right_side(int zero_position, std::vector<int>& a, int n)
{
    for(int i = zero_position + 1; i < n-1; i++)
    { //Numbers to the right of zero shoud be positive and increase
        if(a[i] < 0) a[i] = -a[i];
        int next_elem = a[i+1] < 0 ? -a[i+1] : a[i+1];
        if(a[i] > next_elem)
        {
            return 1;
        }
    }
    a[n-1] = a[n-1] < 0? -a[n-1] : a[n-1];
    return 0;
}

std::vector <int> solution(int n, std::vector<int>& a) 
{
    std::vector<int> result(n+1);
    result[0] = 1;
    //Check for zeros in a
    std::vector <int> zeros;
    for(int i = 0; i < n; i++) 
    {
        if(a[i] == 0)
        {
            zeros.push_back(i);
        }
    }
    
    //Check if zeros more than 1
    if(zeros.size() > 1)
    {
        for(int i = 0; i < zeros.size() - 1; i++)
        {//Is it possible to build a staircase?
            if(zeros[i+1] - zeros[i] > 1)
            {
                result[0] = 0;
                return result;
            }
        }
        int first_zero = zeros[0];
        int last_zero = zeros.back();
        if(left_side(first_zero, a, n))
        {
            result[0] = 0;
            return result;
        }
        if(right_side(last_zero,a, n))
        {
            result[0] = 0;
            return result;
        }

    }
    //Check if only one zero
    else if(zeros.size() == 1)
    {
        if(left_side(zeros[0], a,n))
        {
            result[0] = 0;
            return result;
        }
        if(right_side(zeros[0],a,n))
        {
            result[0] = 0;
            return result;
        }
    }
    //Check if no zero
    else
    {
        a[0] = a[0] > 0 ? -a[0] : a[0];
        for(int i = 1; i < n; i++)
        {
            if(a[i] < a[i-1])
            {
                if(-a[i] >= a[i-1])
                {
                    a[i] = -a[i];
                }
                else
                {
                    result[0] = 0;
                    return result;
                }
            }
            else if(-a[i] >= a[i-1] && a[i] > 0)
            {
                a[i] = -a[i];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        result[i+1] = a[i];
    }
    
    return result;
}