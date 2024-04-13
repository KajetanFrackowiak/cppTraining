#include "Sorting.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Sorting::customSort(std::vector<int>& values) {
	std::sort(values.begin(), values.end(), [](int a, int b) {
		if (a == 2)
			return false;
		if (b == 2)
			return false;
		return a < b;
		});
}

int main() {
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	// std::sort(values.begin(), values.end(), std::greater<int>());
	Sorting::customSort(values);

	for (int value : values)
		std::cout << value << std::endl;

	return 0;
}