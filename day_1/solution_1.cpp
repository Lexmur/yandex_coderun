#include <cmath>

int solution(int n, int m) {

    int minimum = std::min(n,m);
    int num_of_pairs = 0;

    if(n!=m){
        num_of_pairs = 2 * minimum + 1;
    }
    else{
        num_of_pairs = 2 * minimum;
    }
    int len_of_side = (int)(std::sqrt(num_of_pairs));

    return len_of_side;
}
