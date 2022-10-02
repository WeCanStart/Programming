#include <iostream>

int main(){
    int d;
    std::cin >> d;
    if (d % 5 == 0){
        std::cout << d / 5;
    }
    else{
        std::cout << d / 5 + 1;
    }
    return 0;
}