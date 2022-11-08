#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

bool cmp(std::vector<int> lhs, std::vector<int> rhs) {
    int left_cost = lhs[0] + lhs[1] + lhs[2] + lhs[3];
    int right_cost = rhs[0] + rhs[1] + rhs[2] + rhs[3];
    if (left_cost == right_cost) {
        return lhs[4] < rhs[4];
    }
    return right_cost < left_cost;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> table(n, std::vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> table[i][0] >> table[i][1] >> table[i][2] >> table[i][3];
        table[i][4] = i;
    }
    std::sort(table.begin(), table.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (table[i][4] == 0) {
            std::cout << i + 1;
        }
    }
  return 0;
}
