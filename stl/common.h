#pragma once
#include <iostream>
template <class T>
	void PRINT_ELEMENTS(T& tmp) {
		for (auto& elem : tmp) {
			std::cout << elem << ' ';
		}
		std::cout << std::endl;
	}
