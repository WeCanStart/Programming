#include <iostream>
#include <vector>

void solve() {
	bool flag(0);
	for (int i = 1; i <= 8; ++i) {
		int sl(0), sr(0);
		for (int j = 1; j <= 8; ++j) {
			char l(0);
			std::cin >> l;
			if (l == '#') {
				if (sl == 0) {
					sl = j;
				}
				else {
					sr = j;
				}
			}
		}
		if (flag && sr == 0) {
			std::cout << i << ' ' << sl << std::endl;
			for (int a = i + 1; a <= 8; ++a) {
				for (int j = 1; j <= 8; ++j) {
					char l(0);
					std::cin >> l;
				}
			}
			return;
		}
		if (sr != 0) {
			flag = 1;
		}
	}
}

int main()
{
	int t(0);
	std::cin >> t;
	while (t--) {
		solve();
	}
  return 0;
}
