#include <iostream>

int main() {
    int n(0), k(0);
    std::cin >> n >> k;
    int num(0), numw(0);
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        if (k % num == 0 && num > numw) {
            numw = num;
        }
    }
    std::cout << k / numw;
    return 0;
}