#include <iostream>

template<class T>
class MyUnique_ptr
{
public:
	MyUnique_ptr(T* ptr = nullptr) :
		pointer(ptr) {}

	MyUnique_ptr(const MyUnique_ptr& el) = delete;
	MyUnique_ptr(MyUnique_ptr&& el) : pointer(el.pointer)
	{
		el.pointer = nullptr;
	}

	~MyUnique_ptr() { delete pointer; }

	MyUnique_ptr& operator =(const MyUnique_ptr& el) = delete;
	operator bool() const { return pointer; }
	T& operator *() const { return *pointer; }
	T* operator ->() const { return pointer; }

	MyUnique_ptr& operator =(MyUnique_ptr&& el)
	{
		if (&el != this)
		{
			delete pointer;
			pointer = el.pointer;
			el.pointer = nullptr;
			return*this;
		}
		return*this;
	}

	T release()
	{
		T* ans = pointer;
		pointer = nullptr;
		return ans;
	}

	void reset(T ptr = T())
	{
		T* old = pointer;
		pointer = ptr;
		if (old != nullptr) delete old;
	}

	void swap(MyUnique_ptr& el)
	{
		T* temp{ std::move(el) };
		el = std::move(el.pointer);
		el.pointer = temp;
	}
	
private:
	T* pointer;
};

int main()
{
	return 0;
}
