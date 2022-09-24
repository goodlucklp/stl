#include <iostream>
#include <set>
#include "common.h"
using namespace std;

class RunTimeCmp {
	public:
		enum cmp_mode {normal, reverse};
	private:
		cmp_mode mode;
	public:
		RunTimeCmp(cmp_mode m=normal) : mode(m) {

		}
	template<typename T>
		bool operator() (const T& t1, const T& t2) const {
			return mode == normal ? t1 < t2 : t2 < t1;
		}

	bool operator== (const RunTimeCmp& rc) const {
		return mode == rc.mode;
	}
};

typedef set<int, RunTimeCmp> IntSet;

int main() 
{
	IntSet coll1 {4, 7 ,5, 1, 6, 2, 5};
	PRINT_ELEMENTS(coll1);
	RunTimeCmp reverse_order(RunTimeCmp::reverse);

	IntSet coll2(reverse_order);
	coll2 = {4, 7, 5, 1, 6, 2, 5};
	PRINT_ELEMENTS(coll2);

	coll1 = coll2;
	coll1.insert(3);
	PRINT_ELEMENTS(coll1);

	if (coll1.value_comp() == coll2.value_comp()) {
		cout << "coll1 and coll2 have the same sorting\n"
			<< "criterion" << endl;
   	} else {
		cout << "coll1 and coll2 have a diffrent sorting\n"
			 << "criterion " << endl;
	}
	return 0;
}





