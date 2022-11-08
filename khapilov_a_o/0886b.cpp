#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

int main() {
    int n = 0;
    std::cin >> n;
    std::map<int, int> canteen;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        canteen[num] = i;
    }
    int minimal = std::numeric_limits<int>::max();
    int ans = 0;
    for (auto iter = canteen.begin(); iter != canteen.end(); ++iter) {
        if (iter->second < minimal) {
            minimal = iter->second;
            ans = iter->first;
        }
    }
    std::cout << ans;
  return 0;
}
