#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> lock(n, 0);
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		lock[i] = num;
	}
	for (int i = 0; i < n; i++) {
		int cU(0), cD(0);
		int sh;
		std::cin >> sh;
		while (sh--) {
			char l;
			std::cin >> l;
			if (l == 'U') {
				cU++;
			}
			else {
				cD++;
			}
		}
		cD %= 10;
		cU %= 10;
		std::cout << (10 + cD - cU + lock[i]) % 10 << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int t;
	std::cin >> t;
	while (t--) solve();
    return 0;
}