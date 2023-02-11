#include "rational.h"
#include <string>

int main() {
    Rational a(2, 5), b(1, 7);
    int32_t n{ 6 };
    std::cout << a << " + " << b << " -> " << a + b << std::endl;
    std::cout << a << " - " << b << " -> " << a - b << std::endl;
    std::cout << a << " * " << b << " -> " << a * b << std::endl;
    std::cout << a << " / " << b << " -> " << a / b << std::endl;
    std::cout << a << " % " << b << " -> " << a % b << std::endl;
    
    std::cout << a << " ^ " << n << " -> " << pow(a, n) << std::endl;
    std::cout << "sqr(" << a << ") -> " << sqr(a) << std::endl;

    std::cout << a << " < " << b << " -> " << (a < b) << std::endl;
    std::cout << a << " = " << b << " -> " << (a == b) << std::endl;
    std::cout << a << " > " << b << " -> " << (a > b) << std::endl;
    return 0;
}