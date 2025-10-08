#include "NonNegativeArray.hpp"

int main() {

	MTRN2500::NonNegativeArray a1{ MTRN2500::NonNegativeArray({2.0, 3.09555, 4.03, -0.1, -2.1, -5.6}) };
	MTRN2500::NonNegativeArray a2{ MTRN2500::NonNegativeArray({1.5, 1.5, 3.07, 3.07, 3.07, 8, 8, 8, 8, 8.01, 8, -99}) };
	MTRN2500::NonNegativeArray a3{ MTRN2500::NonNegativeArray({1.1, 2.56, 3.47, -1}) };

	std::cout << a1 << '\n';
	std::cout << a2 << '\n';
	std::cout << a3 << '\n';

	return 0;
}