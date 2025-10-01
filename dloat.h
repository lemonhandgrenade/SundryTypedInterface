#pragma once
#include <cmath>
#include <iostream>
#include "sti.h"

namespace sti {
	class dloat {
		float value_;

	public:
		dloat(const double& val) {
			value_ = update(static_cast<float>(val));
		}
		dloat(const float& val) {
			value_ = update(val);
		}
		operator float() const { return value_;}
		dloat operator+(const float& other) const
		{
			return update(value_+other);
		}
		dloat operator+(const int& other) const
		{
			return update(value_+(float)other);
		}
		dloat operator-(const float& other) const
		{
			return update(value_-other);
		}
		dloat operator-(const int& other) const
		{
			return update(value_-(float)other);
		}
		dloat operator*(const float& other) const
		{
			return update(value_*other);
		}
		dloat operator*(const int& other) const
		{
			return update(value_*(float)other);
		}
		dloat operator/(const float& other) const
		{
			return update(value_/other);
		}
		dloat operator/(const int& other) const
		{
			return update(value_/static_cast<float>(other));
		}
	private:
		static float inverse_mod(const float& val, const float& mod) {
			return val - (fmod(val,mod));
		}
		static float update(const float& val)
		{
			
			const float inv_mod = inverse_mod(abs(val),1);
			float overflow{};
			if (abs(val) >= 1)
				overflow = ceil(log10(abs(inv_mod)));
			else
				return val;
			
			float temp = val;
			temp /= pow(10.0f, overflow);
			return temp;
		}
	};



}