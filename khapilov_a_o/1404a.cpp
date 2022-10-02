#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::string s = "";
    std::cin >> s;
    for (int i = 0; i < n - k; i++) {
        char& l = s[i];
        char& r = s[i + k];
        if (l != '?') {
            if (r == '?') {
                r = l;
            }
            else {
                if (l != r) {
                    std::cout << "NO" << std::endl;
                    return;
                }
            }
        }
        else{
            if (r != '?') {
                l = r;
            }
        }
    }
    for (int i = n - 1; i >= k; i--) {
        char& l = s[i - k];
        char& r = s[i];
        if (l != '?') {
            if (r == '?') {
                r = l;
            }
            else {
                if (l != r) {
                    std::cout << "NO" << std::endl;
                    return;
                }
            }
        }
        else {
            if (r != '?') {
                l = r;
            }
        }
    }
    std::vector<int> a = { 0, 0 };
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') {
            a[0]++;
        }
        if (s[i] == '1') {
            a[1]++;
        }
    }
    if (a[0] > k / 2 || a[1] > k / 2) {
        std::cout << "NO" << std::endl;
        return;
    }
    std::cout << "YES" << std::endl;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 0;
    std::cin >> t;
    while (t--) solve();
    return 0;
}