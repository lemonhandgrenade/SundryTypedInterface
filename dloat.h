#pragma once
#include <cmath>

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
		explicit operator float() const { return value_;}
		dloat operator+(const float& other) const
		{
			return dloat(update(value_+other));
		}
		dloat operator+(const int& other) const
		{
			return dloat(update(value_+static_cast<float>(other)));
		}
		dloat operator-(const float& other) const
		{
			return dloat(update(value_-other));
		}
		dloat operator-(const int& other) const
		{
			return dloat(update(value_-static_cast<float>(other)));
		}
		dloat operator*(const float& other) const
		{
			return dloat(update(value_*other));
		}
		dloat operator*(const int& other) const
		{
			return dloat(update(value_*static_cast<float>(other)));
		}
		dloat operator/(const float& other) const
		{
			return dloat(update(value_/other));
		}
		dloat operator/(const int& other) const
		{
			return dloat(update(value_/static_cast<float>(other)));
		}
		bool operator==(const dloat& other) const {
			return std::fabs(value_ - other.value_) < 0.00001f;
		}
		bool operator==(const float& other) const {
			return std::fabs(value_ - other) < 0.00001f;
		}
		bool operator==(const double& other) const {
			return std::fabs(value_ - other) < 0.00001;
		}
	private:
		static float inverse_mod(const float& val, const float& mod) {
			return val - fmod(val,mod);
		}
		static float update(const float& val) {
			if (fabsf(val) < 1.0f) return val;
			const float inv_mod = inverse_mod(fabsf(val),1);
			const float overflow = ceil(log10(inv_mod));
			return val / pow(10.0f, overflow);
		}
	};



}