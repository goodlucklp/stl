#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "common.h"
using namespace std;

int main()
{
	array<int, 10> a {11, 22, 33, 44};
	PRINT_ELEMENTS(a);
	a.back() = 99999999;
	a[a.size()-2] = 42;
	cout << "sum : "
		 << accumulate(a.begin(), a.end(), 0)
	     << endl;

    transform(a.begin(), a.end(),
			  a.begin(), negate<int>());

	PRINT_ELEMENTS(a);
	return 0;
}
