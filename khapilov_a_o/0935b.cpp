#include <iostream>

int main() {
    int n(0);
    std::cin >> n;
    int x(0), y(0), c(0);
    bool k(0), ks(0);
    char sym(0);
    std::cin >> sym;
    if (sym == 'U') {
        ++y;
    }
    else {
        ++x;
    }
    if (y > x) {
        ks = 0;
    }
    if (y < x) {
        ks = 1;
    }
    for (int i = 1; i < n; ++i) {
        std::cin >> sym;
        if (sym == 'U') {
            ++y;
        }
        else {
            ++x;
        }
        if (y > x) {
            k = 0;
        }
        if (y < x) {
            k = 1;
        }
        if (y == x) {
            k = ks;
        }
        if (k != ks) {
            ks = k;
            ++c;
        }
    }
    std::cout << c;
    return 0;
}
