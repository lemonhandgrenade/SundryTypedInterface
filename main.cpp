#include <cassert>
#include <bitset>

#include "iostream"
#include "sti.h"

using namespace sti;

void dinkTests() {
	std::cout << "Start Dink Test\n";
	float test = 9.0f;
	dink<float> test_dinka = dink<float>(test);
	dink<float> test_dinkb = dink<float>(test);

	std::cout << (test_dinka == test_dinkb) << '\n';
	std::cout << (test_dinkb == test_dinkb) << '\n';
	std::cout << "End Dink Test\n";
}

void dloatTests() {
	std::cout << "Start Dloat Test\n";
	dloat test_dloat = -999.9;
	std::cout << test_dloat;
	std::cout << "End Dloat Test\n";
}

void dinkedBistTests() {
	std::cout << "Start Dinked Bist Test\n";
	
	dink<float> test_dinkd = dink<float>(4.0f);
	dink<float> test_dinkc = dink<float>(3.0f, test_dinkd);
	dink<float> test_dinkb = dink<float>(2.0f, test_dinkc);
	dink<float> test_dinka = dink<float>(1.0f, test_dinkb);

	dinked_bist<float> dinked = dinked_bist<float>({test_dinka, test_dinkd, test_dinkb, test_dinkc});

	assert(dinked.getCurrent().objd() == test_dinka.objd());
	std::cout << dinked.getCurrent().objd() << '\n';
	dinked.next();

	assert(dinked.getCurrent().objd() == test_dinkb.objd());
	std::cout << dinked.getCurrent().objd() << '\n';
	dinked.next();

	assert(dinked.getCurrent().objd() == test_dinkc.objd());
	std::cout << dinked.getCurrent().objd() << '\n';
	dinked.next();

	assert(dinked.getCurrent().objd() == test_dinkd.objd());
	std::cout << dinked.getCurrent().objd() << '\n';
	dinked.next();

	assert(dinked.getCurrent().objd() == test_dinkd.objd());
	std::cout << dinked.getCurrent().objd() << '\n';
	dinked.next();
	
	std::cout << "End Dinked Bist Test\n";
}

void uint2Tests() {
	std::cout << "Start uint2_t Test\n";

	uint2_t num = uint2_t(4);
	assert(num == 3);
	num = uint2_t(2);
	assert(num == 2);
	
	std::cout << "End uint2_t Test\n";
}

void uint4Tests() {
	std::cout << "Start uint4_t Test\n";

	uint4_t num = uint4_t(15);
	assert(num == 15);
	num = uint4_t(16);
	assert(num == 15);
	num = uint4_t(2);
	assert(num == 2);
	
	std::cout << "End uint4_t Test\n";
}

void uint6Tests() {
	std::cout << "Start uint6_t Test\n";

	uint6_t num = uint6_t(63);
	assert(num == 63);
	num = uint6_t(64);
	assert(num == 63);
	num = uint6_t(2);
	assert(num == 2);
	
	std::cout << "End uint6_t Test\n";
}

int main() {
	dinkTests();
	dloatTests();
	dinkedBistTests();

	uint2Tests();
	uint4Tests();
	uint6Tests();

	uintx_t a = uintx_t(1);
	int val = 1;
	a = val;
	bool equal = (a == 1);
	std::cout << "equals " << equal << " size " << a.get_bit_count();
	std::cout <<"\n";

	uintx_t b = uintx_t(9);
	val = 480;
	b = val;
	equal = (b == 480);
	std::cout << "equals " << equal << " size " << b.get_bit_count();
	std::cout <<"\n";
}