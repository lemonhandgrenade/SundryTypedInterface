#pragma once
#include <cmath>
#include <iostream>
#include "sti.h"

namespace sti {
	struct dloat {
	private:
	float value;

	public:
		dloat(const float& val) {
			float inv_mod = inverseMod(val,1);
			int overflow = ceil(log10(inv_mod));
			float temp = val;
			temp /= pow(10, overflow);
			value = temp;
		}

		operator float() const { return value;}
	private:
		float inverseMod(const float& val, const float& mod) {
			return val - (fmod(val,mod));
		}
	};



}