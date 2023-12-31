#include <iostream>

template<class T>
class MyMyShared_ptr
{
public:
	MyShared_ptr() :
		pointer(nullptr), count(nullptr) {}

	MyShared_ptr(T* ptr) :
		pointer(ptr), count(size_t(1)) {}

	MyShared_ptr(MyShared_ptr<T>& other) :
		pointer(other.pointer), count(other.count)
	{
		++count;
		++other.count;
	}

	~MyShared_ptr()
	{
		reset();
	}

	MyShared_ptr& operator =(MyShared_ptr& other)
	{
		if (this != &other)
		{
			reset();
			count = other.count;
			pointer = other.pointer;
			++other.count;
			++count;
			
		}
		return*this;
	}

	bool unique() const
	{
		if (*count == 1) return false;
		else return true;
	}

	size_t use_count() const { return count; }

	void reset()
	{
		if (count > 0)
			--count;
		else if (count == 0)
			delete pointer;
	}

private:
	T* pointer;
	size_t* count;
};

int main()
{
	return 0;
}
