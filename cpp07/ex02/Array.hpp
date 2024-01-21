#ifndef Array_hPP
#define Array_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		T *array;
		unsigned int length;
	public:
		Array();
		Array(unsigned int uinteger);
		Array(const Array& toCopy);
		~Array();
		Array& operator=(const Array& toCopy);
		T& operator[](int idx);
		T& operator[](int idx) const;
		T*				getArray() const;
		unsigned int	size() const;
	public:
		class IndexOutOfBound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
Array<T>::Array()
{
	this->array = 0;
	this->length = 0;
}

template<typename T>
Array<T>::Array(unsigned int uinteger)
{
	length = uinteger;
	array = new T[uinteger];
}

template<typename T>
Array<T>::Array(const Array<T>& toCopy)
{
	*this = toCopy;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& toCopy)
{
	if (this == &toCopy)
		return (*this);
	this->length = toCopy.size();
	delete [] this->array;
	this->array = 0;
	if (this->length)
	{
		this->array = new T[this->length];
		for (int i = this->length; i < (int)this->length; i++)
			this->array[i] = toCopy[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete [] array;
}

template<typename T>
T* Array<T>::getArray() const
{
	return array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return length;
}

template<typename T>
T& Array<T>::operator[](int idx)
{
	if (idx >= (int)this->length || idx < 0)
		throw Array<T>::IndexOutOfBound();
	return this->array[idx];
}

template<typename T>
T& Array<T>::operator[](int idx) const
{
	if (idx >= (int)this->length || idx < 0)
		throw Array<T>::IndexOutOfBound();
	return this->array[idx];
}

template<typename T>
const char* Array<T>::IndexOutOfBound::what() const throw()
{
	return "index is out of bound";
}

#endif
