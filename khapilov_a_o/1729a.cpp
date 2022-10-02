#include <iostream>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int t2 = abs(c - b) + abs(c - 1), t1 = (a - 1);
    if (t1 < t2){
        cout << 1 << endl;
    }
    else {
        if (t1 > t2) {
            cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}