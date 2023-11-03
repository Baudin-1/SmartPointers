#include <iostream>
#include <algorithm>
#include <stdexcept>

template <class T>
class MyVector
{
public:

	MyVector() : size(0), arr(nullptr), capacity(size * 2) {}
	MyVector(size_t);
	MyVector(size_t, const T& = T());
	~MyVector() { clear(); }

	size_t _capacity() const { return capacity; }
	size_t _size() const { return size; }
	void clear();
	void pop_back();
	void push_back(const T&);
	void resize(size_t);
	T& front() { return at(0); };
	T& back() { return at(size - 1); }
	T& at(size_t i);
	T& operator [](size_t i) { return arr[i]; }

private:
	T* arr;
	size_t size;
	size_t capacity;
};

int main()
{
	return 0;
}


template<class T>
MyVector<T>::MyVector(size_t newsize) : capacity(newsize * 2), size(newsize)
{
	arr = new T[capacity];

	for (size_t i = 0; i < newsize; ++i)
		arr[i] = 0;
}

template<class T>
MyVector<T>::MyVector(size_t newsize, const T& val) : capacity(2 * newsize), size(newsize)
{
	arr = new T[capacity];

	for (size_t i = 0; i < newsize; ++i)
		arr[i] = val;
}

template<class T>
void MyVector<T>::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<class T>
void MyVector<T>::pop_back()
{
	if (size > 0)
		--size;
}

template<class T>
void MyVector<T>::push_back(const T& el)
{
	if (size == capacity)
	{
		resize(size + 1);
		--size;
	}
	arr[size] = el;
	++size;
}

template<class T>
void MyVector<T>::resize(size_t newsize)
{
	size_t correct_size = std::min(newsize, size);
	T* buffer = new T[correct_size];

	for (size_t i = 0; i < correct_size; ++i) 
		buffer[i] = arr[i];

	delete[] arr;
	size = correct_size;
	capacity = correct_size * 2;
	arr = new T[size];

	for (size_t i = 0; i < correct_size; ++i) 
		arr[i] = buffer[i];
	
	delete[] buffer;
}

template<class T>
T& MyVector<T>::at(size_t i)
{
	if (i > size)
		throw std::out_of_range("Vector subscript out of range!");
	else
		return arr[i];
}
