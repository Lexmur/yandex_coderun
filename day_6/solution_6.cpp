#include <vector>
//Read more at the end of the task
long long solution(int n) {
    if (n < 5) return 0;

    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    //Sieve of Eratosthenes
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    long long count1 = 0;
    long long count3 = 0;
    //Check only odd numbers
    for (int i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            if (i % 4 == 1) count1++;
            else count3++;
        }
    }

    return count1 * count3;
}