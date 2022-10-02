#include <iostream>

void solve()
{
    int n, k, x, y, fixer;
    std::cin >> n >> k >> x >> y;
    fixer = (k + (y - 1) % k - (x - 1) % k);    //модульная арифметика, не могу объяснить
    for (int i = 0; i < n; i++) {               //сразу вывод прогонкой по двум переменным и модульному условию
        for (int j = 0; j < n; j++) {
            if ((i + fixer) % k == j % k) {
                std::cout << "X";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) solve();        //решить каждый вход
    return 0;
}