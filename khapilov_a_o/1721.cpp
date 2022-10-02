#include <iostream>

//Инвариант: кратчайшим путём можно пройти по краю. Если по краю пройти нельзя, то нигде нельзя пройти.

void solve()
{
    int n, m, x, y, d;
    std::cin >> n >> m >> x >> y >> d;
    bool l = false, t = false, r = false, b = false;
    if (x <= d + 1) {                    //по левому краю не пройти
        l = true;
    }
    if (y <= d + 1) {                    //по верхнему краю не пройти
        t = true;
    }
    if (x + d >= n) {                    //по правому краю не пройти
        r = true;
    }
    if (y + d >= m) {                    //по нижнему краю не пройти
        b = true;
    }
    if ((b || l) && (t || r)) {          //нельзя пройти по краям
        std::cout << -1 << std::endl;
    }
    else {                               //можно пройти по краям
        std::cout << n + m - 2 << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve(); //решить каждый вход
    return 0;
}