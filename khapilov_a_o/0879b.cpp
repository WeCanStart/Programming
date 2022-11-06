#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    long long n = 0, k = 0;
    std::cin >> n >> k;
    for (long long i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        q.push(num);
    }
    int a = q.front();
    q.pop();
    int b = 0;
    for (long long c = 0; c < k; ++c) {
        b = q.front();
        q.pop();
        if (a < b) {
            std::swap(a, b);
            c = 0;
        }
        q.push(b);
        if (c > n + 1) {
            std::cout << a;
            return 0;
        }
    }
    std::cout << a;
    return 0;
}
