#include <unordered_map>
#include <cmath>

using namespace std;

const long long MOD = 1e9 - 7538; // 999992462
unordered_map<long long, long long> memo;

long long fast_pow(long long base, long long exp) {
    if (exp == 0) return 1;
    if (base == 0) return 0;
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

long long a(long long n) {
    if (n == 0) return 1;
    if (memo.count(n)) return memo[n];

    long long n2 = n / 2;
    long long n3 = n / 3;
    long long n4 = n / 4;

    long long a2 = a(n2);
    long long a3 = a(n3);
    long long a4 = a(n4);

    long long term1 = fast_pow(a2, a3);
    long long term2 = (5 * a4) % MOD;
    long long term3 = n % MOD;

    long long result = (term1 + term2 + term3) % MOD;
    memo[n] = result;
    return result;
}

long long solution(long long n)
{
    return a(n);
}