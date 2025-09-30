#include "iostream"
#include "sti.h"


void dinkTests() {
	std::cout << "Start Dink Test\n";
	float test = 9.0f;
	sti::dink<float> test_dinka = sti::dink<float>(test);
	sti::dink<float> test_dinkb = sti::dink<float>(test);

	std::cout << (test_dinka == test_dinkb) << '\n';
	std::cout << (test_dinkb == test_dinkb) << '\n';
	std::cout << test_dinkb.hash() << '\n';
	std::cout << "End Dink Test\n";
}

void dloatTests() {
	sti::dloat test_dloat = 999.9;
	std::cout << test_dloat;
}

void dinkedBistTests() {
	std::cout << "Start Dinked Bist Test\n";
	sti::dink<float> test_dinkd = sti::dink<float>(4.0f);
	sti::dink<float> test_dinkc = sti::dink<float>(3.0f, test_dinkd);
	sti::dink<float> test_dinkb = sti::dink<float>(2.0f, test_dinkc);
	sti::dink<float> test_dinka = sti::dink<float>(1.0f, test_dinkb);

	sti::dinked_bist<float> dinked = sti::dinked_bist<float>({test_dinka, test_dinkd, test_dinkb, test_dinkc});

	for (int i = 0; i < 5; i++) {
		std::cout << dinked.getCurrent().objd() << '\n';
		dinked.next();
	}
	
	std::cout << "End Dinked Bist Test\n";
}

int main() {
	dinkTests();
	dloatTests();
	dinkedBistTests();
}