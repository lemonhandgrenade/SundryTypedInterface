#include "iostream"
#include "unordered_set"
#include "sti.h"


void dinkTests() {
	float test = 9.0f;
	sti::dink<float> test_dinka = sti::dink<float>(test);
	sti::dink<float> test_dinkb = sti::dink<float>(test);

	std::cout << (test_dinka == test_dinkb) << std::endl;
	std::cout << (test_dinkb == test_dinkb) << std::endl;
	std::cout << test_dinkb.data_hash << std::endl;
}

void dloatTests() {
	sti::dloat test_dloat = 999.9;
	std::cout << test_dloat;
}


int main() {
	dinkTests();
	dloatTests();
}