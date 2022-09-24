#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
	multiset<string> cities {
		"Bejing",
		"Shanghai",
		"Nanjing",
		"Chongqing",
		"Wuxi",
		"Dalian",
		"Daqing",
		"Dali"
	};

	for (const auto& elems : cities) {
		cout << elems << " ";
	}
	cout << endl;
    cities.insert({"London",
			       "Munich",
				   "Hanover",
				   "Braunschweig"});

	for (const auto& elems : cities) {
		cout << elems << " ";
	}
	cout << endl;
	return 0;
}

