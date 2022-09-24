#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	unordered_multiset<string> cities {
		"Branuschweig",
		"Hanover",
		"Frankfurt",
		"New York",
		"Chicago",
		"Toronto",
		"Paris",
		"Frankfurt"
	};

	for (const auto& elem : cities) {
		cout << elem << " ";
	}
	cout << endl;

	cities.insert({"Landao", "Muinch", "Hanover", "Braunscheweig"});

	for (const auto& elem : cities) {
		cout << elem << " ";
	}
	cout << endl;
	return 0;

}
