#include <array>
#include <string>
#include <iostream>

using namespace std;
#if 0
typename T::const_iterator pos;
for (pos = coll.begin(); pos != coll.end(); ++pos) {
	std::cout << *pos << ' ';
}
#endif
int main()
{
	array<string, 5> coll {"hello", "world"};
	for (int i=0; i< coll.size(); ++i) {
		cout << i << ": " << coll[i] << endl;
	}
}


