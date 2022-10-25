#include <iostream>
#include <vector>
#include <algorithm>

void print_left() {
    std::cout << "1 " << "0 ";
}

void print_right() {
    std::cout << "0 " << "1 ";
}

void solve()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            flag ^= 1;
        }
        flag ^= 1;
        for (int j = 0; j < m / 2; ++j) {
            if ((j + flag) & 1) {
                print_left();
            }
            else {
                print_right();
            }
        }
        std::cout << std::endl;
    }
    return;
}

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
