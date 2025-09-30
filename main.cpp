#include "iostream"
#include "unordered_set"
#include "sti.h"


void dinkTests() {
	float test = 9.0f;
	sti::dink<float> test_dink = sti::dink<float>(test);
	sti::dink<float> test_dinka = sti::dink<float>(test);

	std::cout << (test_dinka == test_dink) << std::endl;
	std::cout << (test_dink == test_dink) << std::endl;
	std::cout << test_dink.data_hash << std::endl;
}


int main() {
	dinkTests();
	
}