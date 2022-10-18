#include <iostream>
#include <vector>
#include <cmath>

int max(int a, int b) {
    return (a > b) ? a : b;
}

std::vector<short> dec_to_tri(int num) {
    std::vector<short> ans = {};
    for (int i = 0; num != 0; ++i) {
        ans.push_back(num % 3);
        num /= 3;
    }
    return ans;
}

int sub_inv_tri(std::vector<short> l, std::vector<short> r) {
    int size = max(l.size(), r.size());
    l.resize(size, 0); r.resize(size, 0);
    int ans(0);
    for (int i = size - 1; i >= 0; --i) {
        ans = ans * 3 + (l[i] - r[i] + 3) % 3;
    }
    std::cout << std::endl;
    return ans;
}

int main() {
    int a(0), c(0);
    std::cin >> a >> c;
    std::vector<short> a_inv_tri = dec_to_tri(a);
    std::vector<short> c_inv_tri = dec_to_tri(c);
    int b = sub_inv_tri(c_inv_tri, a_inv_tri);
    std::cout << b;
    return 0;
}
