#include <vector>
#include <algorithm>
#include <functional>

long long solution(int n, int q, std::vector<long long>& a, std::vector<std::pair<int, int>>& queries) {
    //Array of differences
    std::vector<int> diff(n + 2, 0);
    for (int i = 0; i < q; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        diff[l - 1] += 1;
        diff[r] -= 1;
    }
    //Array of page occurrence frequencies
    std::vector<int> freq_arr(n);
    int current = 0;
    for (int i = 0; i < n; i++) {
        current += diff[i];
        freq_arr[i] = current;
    }
    //Sorting
    std::sort(freq_arr.begin(), freq_arr.end(), std::greater<int>());
    std::sort(a.begin(), a.end(), std::greater<long long>());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += freq_arr[i] * a[i];
    }
    return ans;
}