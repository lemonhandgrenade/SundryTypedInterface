#pragma once

namespace sti {
	template <typename T>
	class bale {
		T* data_;
		size_t size_;
		size_t cap_;

		void resize(size_t new_cap) {
			if (new_cap <= cap_) return;

			T* new_data = static_cast<T*>(operator new(new_cap * sizeof(T)));
			for (size_t i = 0; i < size_; ++i) {
				new (new_data + i) T(std::move(data_[i]));
				data_[i].~T();
			}
			operator delete(data_);

			data_ = new_data;
			cap_ = new_cap;
		}
	public:
		bale() : data_(nullptr), size_(0), cap_(0) {}
		bale(std::initializer_list<T> data) : data_(nullptr), size_(0), cap_(0) {
			size_t data_size = data.size();
			resize(data_size);
        
			size_t i = 0;
			for (const T& item : data) {
				new (data_ + i) T(item);
				++i;
			}
			
			size_ = data_size;
		}
		~bale() {
			for (size_t i = 0; i < size_; ++i) data_[i].~T();
			operator delete(data_);
		}

		T*			begin()			{ return data_; }
		const T*	begin() const	{ return data_; }
		T*			end()			{ return data_ + size_; }
		const T*	end() const		{ return data_ + size_; }
		
		size_t size() const { return size_; }
		size_t capacity() const { return cap_; }

		T& operator[](size_t index) {
			if (index >= size_) throw std::out_of_range("Index Out Of Range");
			return data_[index];
		}
		const T& operator[](size_t index) const {
			if (index >= size_) throw std::out_of_range("Index Out Of Range");
			return data_[index];
		}

		void add(const T& v) {
			if (size_ == cap_) {
				const size_t new_cap = (cap_ == 0) ? 1 : cap_ * 2;
				resize(new_cap);
			}
			new (data_ + size_) T(v);
			++size_;
		}

		void add(T&& v) {
			if (size_ == cap_) {
				const size_t new_cap = (cap_ == 0) ? 1 : cap_ * 2;
				resize(new_cap);
			}

			new (data_ + size_) T(std::move(v));
			++size_;
		}

		bool remove(size_t index) {
			if (index >= size_) throw std::out_of_range("Index Out Of Range");
			data_[index].~T();
			for (size_t i = index; i < size_ - 1; ++i) {
				new (data_ + i) T(std::move(data_[i + 1]));
				data_[i + 1].~T();
			}
			--size_;
			return true;
		}

		bool remove(const T& item) {
			for (size_t i = 0; i < size_; ++i) {
				if (data_[i] == item) {
					return remove(i);
				}
			}
			return false;
		}

		void remove_all(const T& item) {
			size_t i = 0;
			while (i < size_) {
				if (data_[i] == item) remove(i);
				else ++i;
			}
		}

		void pop_back() {
			if (size_ == 0) throw std::underflow_error("Bale Is Empty");
			data_[size_ - 1].~T();
			--size_;
		}

		T pop() {
			if (size_ == 0) throw std::underflow_error("Bale Is Empty");
			T value = std::move(data_[size_ - 1]);
			data_[size_ - 1].~T();
			--size_;
			return value;
		}
		
		void clear() {
			for (size_t i = 0; i < size_; ++i) {
				data_[i].~T();
			}
			size_ = 0;
			cap_ = 0;
		}

		bool empty() const {
			return size_ == 0;
		}

		bool contains(const T& v) {
			for (size_t i = 0; i < size_; ++i) {
				if (data_[i] == v) return true;
			}
			return false;
		}

		size_t count(const T& v) {
			size_t c = 0;
			for (size_t i = 0; i < size_; ++i) {
				if (data_[i] == v) ++c;
			}
			return c;
		}

		void operator<<(const T& v) { this->add(v); }
		bool operator>>(const T& v) { return this->contains(v); }
		
		bool operator-() const { return this->empty(); }
		void operator-=(const T& i) { this->remove(i); }
		T operator--() { return this->pop(); }
		bool operator+() const { return !this->empty(); }
		void operator+=(const T& i) { this->add(i); }
		size_t operator++() const { return this->size_; }
		size_t operator&(const T& i) { return this->count(i); }
	};
}

