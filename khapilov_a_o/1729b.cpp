#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n, k;
    string str, ansa = "", ans = "";
    cin >> n;
    cin >> str;
    n--;
    while (n >= 0) {
        if (str[n] == '0') {
            ansa += char(((int)str[n - 2] - (int)'0') * 10 + (int)str[n - 1] - (int)'0' + (int)'a' - 1);
            n -= 2;
        }
        else {
            ansa += char((int)str[n] + (int)'a' - 1 - (int)'0');
        }
        n--;
    }
    k = size(ansa);
    for (int i = k - 1; i >= 0; i--) {
        ans += ansa[i];
    }
    cout << ans << endl;
}

int main()
{
    int q;
    cin >> q;
for (int i = 0; i < q; i++) {
        solve();
    }
    return 0;
}
