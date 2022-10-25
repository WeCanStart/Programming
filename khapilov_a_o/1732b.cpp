#include <iostream>
#include <vector>
#include <algorithm>

void print_left() {
    std::cout << "1 " << "0 ";
}

void print_right() {
    std::cout << "0 " << "1 ";
}

void solve(){
    int n = 0;
    std::cin >> n;
    std::string str = "";
    std::cin >> str;
    std::reverse(str.begin(), str.end());
    while (str.back() == '0') {
        str.pop_back();
        --n;
    }
    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    std::reverse(str.begin(), str.end());
    char work_sym = str[n - 1];
    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (str[i] != work_sym) {
            ++ans;
            work_sym = str[i];
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }
  return 0;
}
