#ifndef Serializer_HPP
#define Serializer_HPP

#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &toCopy);
		Serializer& operator=(const Serializer &toCopy);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
