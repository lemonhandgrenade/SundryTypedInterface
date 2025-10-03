#pragma once

namespace sti {
	template<typename T>
	class dink {
		T data_;
		size_t data_hash_;
		size_t next_hash_;
		size_t prev_hash_;

	public:
		dink() {
			data_ = NULL;
			data_hash_ = 0;
			next_hash_ = 0;
			prev_hash_ = 0;
		}

		dink(const T& obj) {
			data_ = obj;
			std::hash<T> hasher;
			data_hash_ = hasher(obj);
			next_hash_ = 0;
			prev_hash_ = 0;
		}

		dink(const T& obj, dink& follow) {
			data_ = obj;
			std::hash<T> hasher;
			data_hash_ = hasher(obj);
			next_hash_ = follow.hash();
			prev_hash_ = 0;
			follow.set_prev(data_hash_);
		}

		T data() { return data_; }

		_NODISCARD size_t hash() const { return data_hash_; }
		_NODISCARD size_t next_hash() const { return next_hash_; }
		_NODISCARD size_t prev_hash() const { return prev_hash_; }
		void set_prev(const size_t& hash) { prev_hash_ = hash; }
		
		friend bool operator==(const dink& a, const dink& b) { return a.data_ == b.data_; }
		friend bool operator!=(const dink& a, const dink& b) { return !(a == b); }
		friend bool operator<<(const dink& a, const dink& b) { return &a < &b; }
		friend bool operator>>(const dink& a, const dink& b) { return &a > &b; }
	};
}
