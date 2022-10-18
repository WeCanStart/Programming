#include <iostream>

int main()
{
	int t(0);
	std::cin >> t;
	while (t--) {
		int lb(0), lt(0), rt(0), rb(0);
		std::cin >> lt >> rt >> lb >> rb;
		if (lt + lb + rt + rb == 4) {
			std::cout << 2 << std::endl;
			continue;
		}
		if (lt + lb + rt + rb == 0) {
			std::cout << 0 << std::endl;
			continue;
		}
		std::cout << 1 << std::endl;
		continue;
	}
}
