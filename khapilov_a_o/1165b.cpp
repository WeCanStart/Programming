#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int& a : vec) {
        std::cin >> a;
    }
    std::sort(vec.begin(), vec.end());
    int k = 1;
    for (int i = 0; i < n; ++i) {
        if (vec[i] >= k) {
            ++k;
        }
    }
    std::cout << k - 1;
    return 0;
}
