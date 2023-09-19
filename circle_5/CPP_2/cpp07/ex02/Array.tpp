template <typename T>
Array<T>::Array() {
	arr = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& a) {
	*this = a;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->arr;
}

template <typename T>
Array<T>& Array<T>::operator= (const Array<T>& a) {
	if (this != &a) {
		delete[] this->arr;
		this->arr = new T[a.size()];
		for (size_t i = 0; i < a.size(); i++) {
			this->arr[i] = a.arr[i];
		}
		this->_size = a.size();
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
	return this->_size;
}

template <typename T>
T& Array<T>::operator[] (const size_t& a) const {
	if (a < 0 || this->size() <= a)
		throw OutOfBounds();
	return arr[a];
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
	return ("Out of array boundary");
}
