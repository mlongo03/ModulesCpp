#ifndef Array_CPP
#define Array_CPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T *array;
	public:
		Array();
		Array(unsigned int uinteger);
		Array(const Array& toCopy);
		Array& operator=(const Array& toCopy);
		~Array();
};

#endif
