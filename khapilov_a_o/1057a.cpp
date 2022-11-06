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
    std::cin >> n;
    std::vector<int> web(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        std::cin >> web[i];
    }
    int pointer = n;
    std::vector<int> ans;
    while (pointer > 0) {
        ans.push_back(pointer);
        pointer = web[pointer];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] << ' ';
    }
}
