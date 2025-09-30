#pragma once

namespace sti {
	template<typename T>
	class dink {
		T data_;
		size_t data_hash_;
		size_t next_hash_;

	public:
		dink() {
			data_ = NULL;
			data_hash_ = 0;
			next_hash_ = 0;
		}

		dink(const T& obj) {
			data_ = obj;
			std::hash<T> hasher;
			data_hash_ = hasher(obj);
			next_hash_ = 0;
		}

		dink(const T& obj, dink<T> follow) {
			data_ = obj;
			std::hash<T> hasher;
			data_hash_ = hasher(obj);
			next_hash_ = follow.hash();
		}

		T objd() {
			return data_;
		}

		size_t hash() const {
			return data_hash_;
		}

		size_t nextHash() const {
			return next_hash_;
		}

		friend bool operator==(const dink& a, const dink& b) {
			return &a == &b;
		}

		friend bool operator!=(const dink& a, const dink& b) {
			return !(a == b);
		}

		friend bool operator<<(const dink& a, const dink& b) {
			return &a < &b;
		}

		friend bool operator>>(const dink& a, const dink& b) {
			return &a > &b;
		}
	};
}