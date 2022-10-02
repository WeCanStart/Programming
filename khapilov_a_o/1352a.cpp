#include <iostream>

void solver(int num){
    int count{0}, dev{1};
    int arr[5] = {0, 0, 0, 0, 0};
    for (int i = 0; num != 0; i++){
        dev *= 10;
        int digitlike{num % dev};
        if (digitlike != 0){
            arr[count] = digitlike;
            count += 1;
            num -= digitlike;
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++){
        std::cout << arr[i] << ' ';
    }
}

int main(){
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++){
        int num;
        std::cin >> num;
        solver(num);
    }
    return 0;
}