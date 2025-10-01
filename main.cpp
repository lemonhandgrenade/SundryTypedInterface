#include <cassert>

#include "flag_bearer.h"
#include "iostream"
#include "sti.h"

using namespace sti;

void dinkTests() {
	std::cout << "Start Dink Test\n";
	constexpr int test = 9;
	const dink<int> test_dinka = dink<int>(test);
	const dink<int> test_dinkb = dink<int>(test);

	assert(test_dinka == test_dinkb);
	assert(test_dinka << test_dinkb);
	std::cout << "End Dink Test\n";
}

void dloatTests() {
	std::cout << "Start Dloat Test\n";
	const dloat test_dloat = -999.9;
	std::cout << test_dloat;
	std::cout << "End Dloat Test\n";
}

void dinkedBistTests() {
	std::cout << "Start Dinked Bist Test\n";
	
	dink<int> test_dinkd = dink<int>(4);
	dink<int> test_dinkc = dink<int>(3, test_dinkd);
	dink<int> test_dinkb = dink<int>(2, test_dinkc);
	dink<int> test_dinka = dink<int>(1, test_dinkb);

	dinked_bist<int> dinked = dinked_bist<int>({test_dinka, test_dinkd, test_dinkb, test_dinkc});

	assert(dinked.getCurrent().objd() == test_dinka.objd());
	dinked.next();
	assert(dinked.getCurrent().objd() == test_dinkb.objd());
	dinked.next();
	assert(dinked.getCurrent().objd() == test_dinkc.objd());
	dinked.next();
	assert(dinked.getCurrent().objd() == test_dinkd.objd());
	dinked.next();
	assert(dinked.getCurrent().objd() == test_dinkd.objd());
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

void uintXTests() {
	std::cout << "Start uintx_t Test\n";

	uintx_t num = uintx_t(3, 5);
	assert(num == 5);
	num -= 3;
	assert(num == 2);
	
	std::cout << "End uintx_t Test\n";
}

enum alphabet_enum : uint8_t {flag_a,flag_b,flag_c,flag_d,flag_e,flag_f,flag_g,flag_h,flag_i,flag_j,flag_k,flag_l,flag_m,flag_n,flag_o,flag_p,flag_q,flag_r,flag_s,flag_t,flag_u,flag_v,flag_w,flag_x,flag_y,flag_z};

void flagBearerTests() {
	std::cout << "Start flag_bearer Test\n";

	flag_bearer<alphabet_enum> fb = flag_bearer<alphabet_enum>(flag_z + 1);
	fb.set_flag(flag_a, true);
	fb.set_flag(flag_t, true);
	fb.set_flag(flag_y, true);
	fb.set_flag(flag_z, true);
	assert(fb.get_flag(flag_a));
	assert(fb.get_flag(flag_t));
	assert(fb.get_flag(flag_y));
	assert(fb.get_flag(flag_z));
	std::cout << "End flag_bearer Test\n";
}

int main() {
	dinkTests();
	dloatTests();
	dinkedBistTests();

	uint2Tests();
	uint4Tests();
	uint6Tests();
	uintXTests();
	
	flagBearerTests();
}