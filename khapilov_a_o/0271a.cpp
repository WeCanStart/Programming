#include <iostream>

int main(){
    int y{0};
    std::cin >> y;
    int a{0}, b{0}, c{0}, d{0};
    do{
        y += 1;
        a = y / 1000;
        b = (y - a * 1000) / 100;
        c = (y - a * 1000 - b * 100) / 10;
        d = y % 10;
    }while (a == b || a == c || a == d || b == c || b == d || c == d);
    std::cout << y;
}