#include <iostream>
#include <vector>
#include <algorithm>
#include <string>




int max(int l, int r) {
    return (l > r) ? l : r;
}
int min(int l, int r) {
    return (l < r) ? l : r;
}




int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<bool> is_prime(3 * n + 1, true);
    for (int i = 2; i <= n * 3; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int prev = -1;
    int cur = 2;
    int count_of_correct = 0;
    for (int i = 3; cur + prev + 1 <= n; ++i) {
        if (is_prime[i]) {
            prev = cur;
            cur = i;
            if (is_prime[prev + cur + 1] && cur + prev + 1 <= n) {
                ++count_of_correct;
            }
        }
    }
    if (count_of_correct >= k) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}
