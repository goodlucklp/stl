#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int square(int value)
{
	return value * value;
}

int main()
{
	std::set<int> coll1;
	std::vector<int> coll2;

	for (int i=1;i<=9; ++i) {
		coll1.insert(i);
	}

	std::transform(coll1.cbegin(), coll1.cend(),
		std::back_inserter(coll2), square);

	for (auto& elem : coll2) {
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
	return 0;
} 
